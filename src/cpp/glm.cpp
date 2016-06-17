#include "glm.h"

namespace statiskit
{
    namespace glm
    {              
        PoissonRegression::PoissonRegression(const ScalarPredictor& predictor, const PoissonLink& link) :  GeneralizedLinearModel< DiscreteUnivariateConditionalDistribution, PoissonLink >(predictor, link)
        { _family = new PoissonDistribution(std::numeric_limits< double >::quiet_NaN()); }

        void PoissonRegression::update(const double& value)
        { _family->set_theta(value); } 
        
                    
        BinomialRegression::BinomialRegression(const unsigned int& kappa, const ScalarPredictor& predictor, const BinomialLink& link) :  GeneralizedLinearModel< DiscreteUnivariateConditionalDistribution, BinomialLink >(predictor, link)
        { _family = new BinomialDistribution(kappa, std::numeric_limits< double >::quiet_NaN()); }

        void BinomialRegression::update(const double& value)
        { _family->set_pi(value); }    
        
        
        NegativeBinomialRegression::NegativeBinomialRegression(const unsigned int& kappa, const ScalarPredictor& predictor, const NegativeBinomialLink& link) :  GeneralizedLinearModel< DiscreteUnivariateConditionalDistribution, NegativeBinomialLink >(predictor, link)
        { _family = new NegativeBinomialDistribution(kappa, std::numeric_limits< double >::quiet_NaN()); }

        void NegativeBinomialRegression::update(const double& value)
        { _family->set_pi(value); } 
        
        
        NominalRegression::NominalRegression(const std::set< std::string >& values, const VectorPredictor& predictor, const NominalLink& link) :  GeneralizedLinearModel< CategoricalUnivariateConditionalDistribution, NominalLink >(predictor, link)
        { _family = new NominalDistribution(values); }

        void NominalRegression::update(const std::vector< double >& values)
        { _family->set_pi(values); }   

        
        OrdinalRegression::OrdinalRegression(const std::vector< std::string >& values, const VectorPredictor& predictor, const OrdinalLink& link) :  GeneralizedLinearModel< CategoricalUnivariateConditionalDistribution, OrdinalLink >(predictor, link)
        { _family = new OrdinalDistribution(values); }

        void OrdinalRegression::update(const std::vector< double >& values)
        { _family->set_pi(values); }                                
    }
}