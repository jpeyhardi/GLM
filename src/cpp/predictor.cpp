/**********************************************************************************/
/*                                                                                */
/* StatisKit-CoreThis software is distributed under the CeCILL-C license. You     */
/* should have received a copy of the legalcode along with this work. If not, see */
/* <http://www.cecill.info/licences/Licence_CeCILL-C_V1-en.html>.                 */
/*                                                                                */
/**********************************************************************************/

#include "predictor.h"
#include <eigen3/unsupported/Eigen/KroneckerProduct>

namespace statiskit
{
    ScalarPredictor::ScalarPredictor(const MultivariateSampleSpace& explanatory_space)
    { _explanatory_space = explanatory_space.copy().release(); }

    ScalarPredictor::~ScalarPredictor()
    { delete _explanatory_space; }

    ScalarPredictor::ScalarPredictor(const ScalarPredictor& predictor)
    { _explanatory_space = predictor._explanatory_space->copy().release(); }

    const MultivariateSampleSpace* ScalarPredictor::get_explanatory_space() const
    { return _explanatory_space; }


    CompleteScalarPredictor::CompleteScalarPredictor(const MultivariateSampleSpace& explanatory_space) : CompleteScalarPredictor(explanatory_space, explanatory_space.encode())
    {}

    CompleteScalarPredictor::CompleteScalarPredictor(const MultivariateSampleSpace& explanatory_space, const size_t& size) : ScalarPredictor(explanatory_space)
    {
        alpha = 0.;
        _delta = Eigen::VectorXd::Zero(size);
    }

    CompleteScalarPredictor::CompleteScalarPredictor(const CompleteScalarPredictor& predictor) : ScalarPredictor(predictor)
    {
        alpha = predictor.alpha;
        _delta = predictor._delta;
    }
     
    double CompleteScalarPredictor::operator() (const MultivariateEvent& event) const
    { return alpha + _explanatory_space->encode(event) * _delta; }

	void CompleteScalarPredictor::set_beta(const Eigen::VectorXd& beta)
	{
		if(beta.rows() != (1 + _delta.rows()) )
		{ throw statiskit::size_error("beta", beta.rows(), 1+_delta.rows()); }	
		alpha = beta(0);
		_delta = beta.segment(1, _delta.rows());
	}
	
	size_t CompleteScalarPredictor::size() const
	{ return (1+_delta.size()); }
	
	const Eigen::VectorXd& CompleteScalarPredictor::get_delta() const
	{ return _delta; }

    std::unique_ptr< ScalarPredictor > CompleteScalarPredictor::copy() const
    { return std::make_unique< CompleteScalarPredictor >(*this); }


    ConstrainedScalarPredictor::ConstrainedScalarPredictor(const MultivariateSampleSpace& explanatory_space, const Eigen::MatrixXd& constraint) : CompleteScalarPredictor(explanatory_space, constraint.cols())
    { 
    	if(constraint.rows() != explanatory_space.encode() )
    	{ throw statiskit::size_error("constraint", constraint.rows(), explanatory_space.encode() ); } 
    	if(constraint.cols() > constraint.rows())
    	{ throw statiskit::size_error("constraint", constraint.cols(), constraint.rows(), statiskit::size_error::size_type::superior); }     	   
    	_constraint = constraint; 
    }

    ConstrainedScalarPredictor::ConstrainedScalarPredictor(const ConstrainedScalarPredictor& predictor) : CompleteScalarPredictor(predictor)
    { _constraint = predictor._constraint; }
     
    double ConstrainedScalarPredictor::operator() (const MultivariateEvent& event) const
    { return alpha + _explanatory_space->encode(event) * _constraint * _delta; }
    
    const Eigen::MatrixXd& ConstrainedScalarPredictor::get_constraint() const
    { return _constraint; }
    
	void ConstrainedScalarPredictor::set_constraint(const Eigen::MatrixXd& constraint)
	{
		if(constraint.rows() != _constraint.rows())
		{ throw statiskit::size_error("constraint", constraint.rows(), _constraint.rows()); }
		if(constraint.cols() != _constraint.cols())
		{ throw statiskit::size_error("constraint", constraint.cols(), _constraint.cols()); }			
		_constraint = constraint;
	}
	
    std::unique_ptr< ScalarPredictor > ConstrainedScalarPredictor::copy() const
    { return std::make_unique< ConstrainedScalarPredictor >(*this); }
    

    VectorPredictor::VectorPredictor(const MultivariateSampleSpace& explanatory_space)
    { _explanatory_space = explanatory_space.copy().release(); }
  
    VectorPredictor::~VectorPredictor()
    {} 
    
    VectorPredictor::VectorPredictor(const VectorPredictor& predictor)
    { _explanatory_space = predictor._explanatory_space; }
    
    const MultivariateSampleSpace* VectorPredictor::get_explanatory_space() const
    { return _explanatory_space; }
    

    CompleteVectorPredictor::CompleteVectorPredictor(const MultivariateSampleSpace& explanatory_space, const size_t& dimension) : VectorPredictor(explanatory_space)
    {
    	_alpha = Eigen::VectorXd::Zero(dimension);
    	_delta = Eigen::MatrixXd::Zero(dimension, explanatory_space.encode()); 
    }
    
    CompleteVectorPredictor::CompleteVectorPredictor(const CompleteVectorPredictor& predictor) : VectorPredictor(predictor)
    {
    	_alpha = predictor._alpha; 
    	_delta = predictor._delta; 
    }

    Eigen::VectorXd CompleteVectorPredictor::operator() (const MultivariateEvent& event) const
    { return _alpha + _delta * (_explanatory_space->encode(event)).transpose(); }
    
    size_t CompleteVectorPredictor::size() const
    { return _alpha.rows() + _delta.size(); }
            
    void CompleteVectorPredictor::set_beta(const Eigen::VectorXd& beta)
	{
		if(beta.rows() != _alpha.rows() + _delta.rows() * _delta.cols())
		{ throw statiskit::size_error("beta", beta.rows(),  _alpha.rows() + _delta.rows() * _delta.cols()); }
		_alpha = beta.segment(0, _alpha.rows() -1);
		for(size_t j=0; j<_alpha.rows(); ++j)
        { _delta.block(j, 0, 1, _delta.cols()) = ( beta.segment(_alpha.rows() + j * _delta.cols(), _alpha.rows() + (j+1) * _delta.cols() - 1) ).transpose(); }
	}
		
	const Eigen::VectorXd& CompleteVectorPredictor::get_alpha() const
	{ return _alpha; }		
		
	const Eigen::MatrixXd& CompleteVectorPredictor::get_delta() const
	{ return _delta; }
	
    std::unique_ptr< VectorPredictor > CompleteVectorPredictor::copy() const
    { return std::make_unique< CompleteVectorPredictor >(*this); }	
    
       
    ProportionalVectorPredictor::ProportionalVectorPredictor(const MultivariateSampleSpace& explanatory_space, const size_t& dimension) : VectorPredictor(explanatory_space)
    {
    	_alpha = Eigen::VectorXd::Zero(dimension); 
    	_delta = Eigen::VectorXd::Zero(explanatory_space.encode());
    }
    
    ProportionalVectorPredictor::ProportionalVectorPredictor(const ProportionalVectorPredictor& predictor) : VectorPredictor(predictor)
    {
     	_alpha = predictor._alpha;
    	_delta = predictor._delta; 
    }
	
    Eigen::VectorXd ProportionalVectorPredictor::operator() (const MultivariateEvent& event) const
    { return _alpha + _explanatory_space->encode(event) * _delta; }
    
    size_t ProportionalVectorPredictor::size() const
    { return _alpha.rows() + _delta.rows(); }
            
    void ProportionalVectorPredictor::set_beta(const Eigen::VectorXd& beta)
	{
		if(beta.rows() != _alpha.rows() + _delta.rows() * _delta.cols())
		{ throw statiskit::size_error("beta", beta.rows(),  _alpha.rows() + _delta.rows() * _delta.cols()); }
		_alpha = beta.segment(0, _alpha.rows() -1);
		_delta = beta.segment(_alpha.rows(), _alpha.rows() + _delta.cols() - 1);
	}
		
	const Eigen::VectorXd& ProportionalVectorPredictor::get_alpha() const
	{ return _alpha; }		
		
	const Eigen::VectorXd& ProportionalVectorPredictor::get_delta() const
	{ return _delta; }
	
    std::unique_ptr< VectorPredictor > ProportionalVectorPredictor::copy() const
    { return std::make_unique< ProportionalVectorPredictor >(*this); }	


    ConstrainedVectorPredictor::ConstrainedVectorPredictor(const MultivariateSampleSpace& explanatory_space, const size_t& dimension, const Eigen::MatrixXd& constraint) : ProportionalVectorPredictor(explanatory_space, dimension)
    { 
    	if(constraint.rows() != ( explanatory_space.encode() * dimension ) )
    	{ throw statiskit::size_error("constraint", constraint.rows(),  explanatory_space.encode() * dimension ); } 
    	if(constraint.cols() > constraint.rows())
    	{ throw statiskit::size_error("constraint", constraint.cols(), constraint.rows(), statiskit::size_error::size_type::superior); }     	   
    	_constraint = constraint; 
    	_intercept_constraint = Eigen::MatrixXd::Identity(dimension, dimension);
    }
    
    ConstrainedVectorPredictor::ConstrainedVectorPredictor(const MultivariateSampleSpace& explanatory_space, const Eigen::MatrixXd& constraint, const Eigen::MatrixXd& intercept_constraint) : ProportionalVectorPredictor(explanatory_space, intercept_constraint.rows())
    { 
    	if(constraint.rows() != ( explanatory_space.encode() * intercept_constraint.rows()) )
    	{ throw statiskit::size_error("constraint", constraint.rows(),  explanatory_space.encode() * intercept_constraint.rows()); } 
    	if(constraint.cols() >  constraint.rows())
    	{ throw statiskit::size_error("constraint", constraint.cols(), constraint.rows(), statiskit::size_error::size_type::superior); } 
    	_constraint = constraint;
    	if(intercept_constraint.cols() > intercept_constraint.rows() )
    	{ throw statiskit::size_error("intercept_constraint", intercept_constraint.cols(), intercept_constraint.rows(), statiskit::size_error::size_type::superior); }     	    	   
    	_intercept_constraint = intercept_constraint; 
    }    

    ConstrainedVectorPredictor::ConstrainedVectorPredictor(const ConstrainedVectorPredictor& predictor) : ProportionalVectorPredictor(predictor)
    { 
    	_constraint = predictor._constraint; 
    	_intercept_constraint = predictor._intercept_constraint;
    }
     
    Eigen::VectorXd ConstrainedVectorPredictor::operator() (const MultivariateEvent& event) const
    { return _intercept_constraint * _alpha +  Eigen::kroneckerProduct(Eigen::MatrixXd::Identity(_intercept_constraint.rows(), _intercept_constraint.rows()), _explanatory_space->encode(event)) * _constraint * _delta;}
    
    const Eigen::MatrixXd& ConstrainedVectorPredictor::get_constraint() const
    { return _constraint; }
    
	void ConstrainedVectorPredictor::set_constraint(const Eigen::MatrixXd& constraint)
	{
		if(constraint.rows() != _constraint.rows())
		{ throw statiskit::size_error("constraint", constraint.rows(), _constraint.rows()); }
		if(constraint.cols() != _constraint.cols())
		{ throw statiskit::size_error("constraint", constraint.cols(), _constraint.cols()); }			
		_constraint = constraint;
	}
	
    const Eigen::MatrixXd& ConstrainedVectorPredictor::get_intercept_constraint() const
    { return _intercept_constraint; }
    
	void ConstrainedVectorPredictor::set_intercept_constraint(const Eigen::MatrixXd& intercept_constraint)
	{
		if(intercept_constraint.rows() != _intercept_constraint.rows())
		{ throw statiskit::size_error("intercept_constraint", intercept_constraint.rows(), _intercept_constraint.rows()); }
		if(intercept_constraint.cols() != _intercept_constraint.cols())
		{ throw statiskit::size_error("intercept_constraint", intercept_constraint.cols(), _intercept_constraint.cols()); }			
		_intercept_constraint = intercept_constraint;
	}	
	
    std::unique_ptr< VectorPredictor > ConstrainedVectorPredictor::copy() const
    { return std::make_unique< ConstrainedVectorPredictor >(*this); }
}
