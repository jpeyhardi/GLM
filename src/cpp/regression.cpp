#include "regression.h"

namespace statiskit
{
    namespace glm
    {              
        PoissonRegression::PoissonRegression(const ScalarPredictor& predictor, const PoissonLink& link) :  DiscreteGeneralizedLinearModel< PoissonLink >(predictor, link)
        { _family = new PoissonDistribution(std::numeric_limits< double >::quiet_NaN()); }
        
		std::unique_ptr< UnivariateConditionalDistribution > PoissonRegression::copy() const
		{ return std::make_unique< PoissonRegression >(*this); }

        void PoissonRegression::update(const double& value) const
        { _family->set_theta(value); } 
                    
        BinomialRegression::BinomialRegression(const unsigned int& kappa, const ScalarPredictor& predictor, const BinomialLink& link) :  DiscreteGeneralizedLinearModel< BinomialLink >(predictor, link)
        { _family = new BinomialDistribution(kappa, std::numeric_limits< double >::quiet_NaN()); }
        
        unsigned int BinomialRegression::get_kappa() const
        { return _family->get_kappa(); }
        
        void BinomialRegression::set_kappa(const unsigned int& kappa)
        { _family->set_kappa(kappa); }

		std::unique_ptr< UnivariateConditionalDistribution > BinomialRegression::copy() const
        { return std::make_unique< BinomialRegression >(*this); }

        void BinomialRegression::update(const double& value) const
        { _family->set_pi(value); }    
        
        NegativeBinomialRegression::NegativeBinomialRegression(const double& kappa, const ScalarPredictor& predictor, const NegativeBinomialLink& link) :  DiscreteGeneralizedLinearModel< NegativeBinomialLink >(predictor, link)
        { _family = new NegativeBinomialDistribution(kappa, std::numeric_limits< double >::quiet_NaN()); }
        
        double NegativeBinomialRegression::get_kappa() const
        { return _family->get_kappa(); }
        
        void NegativeBinomialRegression::set_kappa(const double& kappa)
        { _family->set_kappa(kappa); }

		std::unique_ptr< UnivariateConditionalDistribution > NegativeBinomialRegression::copy() const
		{ return std::make_unique< NegativeBinomialRegression >(*this); }
		
        void NegativeBinomialRegression::update(const double& value) const
        { _family->set_pi(value / (1 + value)); } 
        
        NominalRegression::NominalRegression(const std::set< std::string >& values, const VectorPredictor& predictor, const NominalLink& link) :  CategoricalGeneralizedLinearModel< NominalLink >(predictor, link)
        { _family = new NominalDistribution(values); }
        
		std::unique_ptr< UnivariateConditionalDistribution > NominalRegression::copy() const
		{ return std::make_unique< NominalRegression >(*this); }
		
        void NominalRegression::update(const Eigen::VectorXd& values) const
        { _family->set_pi(values); }   
        
        OrdinalRegression::OrdinalRegression(const std::vector< std::string >& values, const VectorPredictor& predictor, const OrdinalLink& link) :  CategoricalGeneralizedLinearModel< OrdinalLink >(predictor, link)
        { _family = new OrdinalDistribution(values); }
        
		std::unique_ptr< UnivariateConditionalDistribution > OrdinalRegression::copy() const
		{ return std::make_unique< OrdinalRegression >(*this); }
		
        void OrdinalRegression::update(const Eigen::VectorXd& values) const
        { _family->set_ordered_pi(values); }                                
    }
}
