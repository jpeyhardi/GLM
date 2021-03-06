#include "estimator.h"

namespace statiskit
{
    namespace glm
    {
        //NominalRegressionFisherEstimation::Estimator nominal();

        PoissonRegressionFisherEstimation::PoissonRegressionFisherEstimation(PoissonRegression const * estimated, UnivariateConditionalData const * data) : QuantitativeScalarRegressionFisherEstimation< PoissonRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimated, data)
        {}

        PoissonRegressionFisherEstimation::PoissonRegressionFisherEstimation(const PoissonRegressionFisherEstimation & estimation) : QuantitativeScalarRegressionFisherEstimation< PoissonRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimation)
        {}

        std::unique_ptr< UnivariateConditionalDistributionEstimation > PoissonRegressionFisherEstimation::copy() const
        { return std::make_unique< PoissonRegressionFisherEstimation >(*this); }

        PoissonRegressionFisherEstimation::Estimator::Estimator() : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, QuantitativeScalarRegressionFisherEstimation< PoissonRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >()
        { _link = new PoissonCanonicalLink(); }

        PoissonRegressionFisherEstimation::Estimator::Estimator(const Estimator& estimator) : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, QuantitativeScalarRegressionFisherEstimation< PoissonRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >(estimator)
        {}        

        double PoissonRegressionFisherEstimation::Estimator::sigma_square(const double& mu) const
        { return mu; }
        
        PoissonRegression * PoissonRegressionFisherEstimation::Estimator::build_estimated(const Eigen::VectorXd& beta, const UnivariateConditionalData& data) const
        {
        	CompleteScalarPredictor predictor = CompleteScalarPredictor(*(data.get_explanatories()->get_sample_space()));
        	predictor.set_beta(beta);
        	return new PoissonRegression(predictor, *_link);
        }
        
        BinomialRegressionFisherEstimation::BinomialRegressionFisherEstimation(BinomialRegression const * estimated, UnivariateConditionalData const * data) : QuantitativeScalarRegressionFisherEstimation< BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimated, data)
        {}

        BinomialRegressionFisherEstimation::BinomialRegressionFisherEstimation(const BinomialRegressionFisherEstimation & estimation) : QuantitativeScalarRegressionFisherEstimation< BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimation)
        {}

        std::unique_ptr< UnivariateConditionalDistributionEstimation > BinomialRegressionFisherEstimation::copy() const
        { return std::make_unique< BinomialRegressionFisherEstimation >(*this); }

        BinomialRegressionFisherEstimation::Estimator::Estimator() : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, QuantitativeScalarRegressionFisherEstimation< BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >()
        { 
            _link = new BinomialCanonicalLink(); 
            _kappa = 0;
        }
        
        BinomialRegressionFisherEstimation::Estimator::Estimator(const Estimator& estimator) : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, QuantitativeScalarRegressionFisherEstimation< BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >(estimator)
        { _kappa = estimator._kappa; }
                
        unsigned int BinomialRegressionFisherEstimation::Estimator::get_kappa() const
        { return _kappa; }

        void BinomialRegressionFisherEstimation::Estimator::set_kappa(const unsigned int& kappa)
        { _kappa = kappa; }

        double BinomialRegressionFisherEstimation::Estimator::sigma_square(const double& mu) const
        { return mu * (1 - mu) / _kappa; }
        
        BinomialRegression * BinomialRegressionFisherEstimation::Estimator::build_estimated(const Eigen::VectorXd& beta, const UnivariateConditionalData& data) const
        {
        	CompleteScalarPredictor predictor = CompleteScalarPredictor(*(data.get_explanatories()->get_sample_space()));
        	predictor.set_beta(beta);
        	return new BinomialRegression(_kappa, predictor, *_link);
        }
        
        Eigen::VectorXd BinomialRegressionFisherEstimation::Estimator::y_init(const UnivariateConditionalData& data) const
        { return QuantitativeScalarRegressionFisherEstimation< BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator::y_init(data) / _kappa; }
        
        BinomialRegressionSteepestAscentEstimation::BinomialRegressionSteepestAscentEstimation(BinomialRegression const * estimated, UnivariateConditionalData const * data) : OptimizationEstimation<unsigned int, BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimated, data)
        {}

        BinomialRegressionSteepestAscentEstimation::BinomialRegressionSteepestAscentEstimation(const BinomialRegressionSteepestAscentEstimation & estimation) : OptimizationEstimation<unsigned int, BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimation)
        {}

        std::unique_ptr< UnivariateConditionalDistributionEstimation > BinomialRegressionSteepestAscentEstimation::copy() const
        { return std::make_unique< BinomialRegressionSteepestAscentEstimation >(*this); }

        BinomialRegressionSteepestAscentEstimation::Estimator::Estimator() : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, OptimizationEstimation<unsigned int, BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >()
        { _estimator = new BinomialRegressionFisherEstimation::Estimator(); }
        
        BinomialRegressionSteepestAscentEstimation::Estimator::Estimator(const Estimator& estimator) : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, OptimizationEstimation<unsigned int, BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >(estimator)
        { _estimator = estimator._estimator; }

        BinomialRegressionSteepestAscentEstimation::Estimator::~Estimator()
        {
            if(_estimator)
            {
                delete _estimator;
                _estimator = nullptr;
            }
        }

        std::unique_ptr< UnivariateConditionalDistributionEstimation > BinomialRegressionSteepestAscentEstimation::Estimator::operator()(const UnivariateConditionalData& data, const bool& lazy) const
        {
            std::unique_ptr< UnivariateEvent > maximum = data.get_response()->compute_maximum();
            if(!maximum || !maximum->get_outcome() == DISCRETE || !maximum->get_event() == ELEMENTARY)
            { throw statiskit::sample_space_error(DISCRETE); }
            unsigned int its = 0;
            BinomialRegression* binomial = new BinomialRegression(static_cast< DiscreteElementaryEvent* >(maximum.get())->get_value(), CompleteScalarPredictor(*(data.get_explanatories()->get_sample_space())), *(_estimator->get_link()));
            std::unique_ptr< UnivariateConditionalDistributionEstimation > estimation;
            if(!lazy)
            { estimation = std::make_unique< BinomialRegressionSteepestAscentEstimation  >(binomial, &data); }
            else
            { estimation = std::make_unique< LazyEstimation< BinomialRegression, DiscreteUnivariateConditionalDistributionEstimation > >(binomial); }
            _estimator->set_kappa(binomial->get_kappa());
            double prev, curr = - 1 * std::numeric_limits< double >::infinity();
            do
            {
                prev = curr;
                std::unique_ptr< UnivariateConditionalDistributionEstimation > _estimation =(*_estimator)(data, true);
                binomial->set_predictor(*(static_cast< const BinomialRegression* >(_estimation->get_estimated())->get_predictor()));
                curr = binomial->loglikelihood(data);
                if(!lazy)
                { static_cast< BinomialRegressionSteepestAscentEstimation * >(estimation.get())->_iterations.push_back(binomial->get_kappa()); }
                if(curr > prev)
                { 
                    _estimator->set_kappa(binomial->get_kappa() + 1);
                    binomial->set_kappa(_estimator->get_kappa());
                }
                ++its;
            } while(run(its, __impl::reldiff(prev, curr)) && prev < curr);
            if(curr < prev)
            {
                _estimator->set_kappa(binomial->get_kappa() - 1);
                std::unique_ptr< UnivariateConditionalDistributionEstimation > _estimation =(*_estimator)(data, true);
                binomial->set_predictor(*(static_cast< const BinomialRegression* >(_estimation->get_estimated())->get_predictor()));
                binomial->set_kappa(_estimator->get_kappa());
            }
            return estimation;
        }

        NegativeBinomialRegressionFisherEstimation::NegativeBinomialRegressionFisherEstimation(NegativeBinomialRegression const * estimated, UnivariateConditionalData const * data) : QuantitativeScalarRegressionFisherEstimation< NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimated, data)
        {}

        NegativeBinomialRegressionFisherEstimation::NegativeBinomialRegressionFisherEstimation(const NegativeBinomialRegressionFisherEstimation & estimation) : QuantitativeScalarRegressionFisherEstimation< NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimation)
        {}     

        std::unique_ptr< UnivariateConditionalDistributionEstimation > NegativeBinomialRegressionFisherEstimation::copy() const
        { return std::make_unique< NegativeBinomialRegressionFisherEstimation >(*this); }

        NegativeBinomialRegressionFisherEstimation::Estimator::Estimator() :  PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, QuantitativeScalarRegressionFisherEstimation< NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >()
        { 
            _link = new NegativeBinomialVLink();
            _kappa = 0.;
        }
        
        NegativeBinomialRegressionFisherEstimation::Estimator::Estimator(const Estimator& estimator) :  PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, QuantitativeScalarRegressionFisherEstimation< NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >(estimator)
        { _kappa = estimator._kappa; }
                        
        double NegativeBinomialRegressionFisherEstimation::Estimator::get_kappa() const
        { return _kappa; }

        void NegativeBinomialRegressionFisherEstimation::Estimator::set_kappa(const double& kappa)
        { _kappa = kappa; }

        double NegativeBinomialRegressionFisherEstimation::Estimator::sigma_square(const double& mu) const
        { return mu * (1 + mu) / _kappa; }

        NegativeBinomialRegression * NegativeBinomialRegressionFisherEstimation::Estimator::build_estimated(const Eigen::VectorXd& beta, const UnivariateConditionalData& data) const
        {
        	CompleteScalarPredictor predictor = CompleteScalarPredictor(*(data.get_explanatories()->get_sample_space()));
        	predictor.set_beta(beta);
        	return new NegativeBinomialRegression(_kappa, predictor, *_link);
        }
        
        Eigen::VectorXd NegativeBinomialRegressionFisherEstimation::Estimator::y_init(const UnivariateConditionalData& data) const
        { return QuantitativeScalarRegressionFisherEstimation< NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator::y_init(data) / _kappa; } 

        NegativeBinomialRegressionX2Estimation::NegativeBinomialRegressionX2Estimation(NegativeBinomialRegression const * estimated, UnivariateConditionalData const * data) : OptimizationEstimation<double, NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimated, data)
        {}

        NegativeBinomialRegressionX2Estimation::NegativeBinomialRegressionX2Estimation(const NegativeBinomialRegressionX2Estimation & estimation) : OptimizationEstimation<double, NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >(estimation)
        {}

        std::unique_ptr< UnivariateConditionalDistributionEstimation > NegativeBinomialRegressionX2Estimation::copy() const
        { return std::make_unique< NegativeBinomialRegressionX2Estimation >(*this); }

        NegativeBinomialRegressionX2Estimation::Estimator::Estimator() : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, OptimizationEstimation<double, NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >()
        { _estimator = new NegativeBinomialRegressionFisherEstimation::Estimator(); }
        
        NegativeBinomialRegressionX2Estimation::Estimator::Estimator(const Estimator& estimator) : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, OptimizationEstimation<double, NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation >::Estimator >(estimator)
        { _estimator = estimator._estimator; }

        NegativeBinomialRegressionX2Estimation::Estimator::~Estimator()
        {
            if(_estimator)
            {
                delete _estimator;
                _estimator = nullptr;
            }
        }

        std::unique_ptr< UnivariateConditionalDistributionEstimation > NegativeBinomialRegressionX2Estimation::Estimator::operator() (const UnivariateConditionalData& data, const bool& lazy) const
        {
            const UnivariateData* response = data.get_response();
            UnivariateMeanEstimation::Estimator location_estimator = UnivariateMeanEstimation::Estimator();
            std::unique_ptr< UnivariateLocationEstimation > location_estimation = location_estimator(*response);
            double total = data.compute_total(), mean = location_estimation->get_location(), prev, curr = 0;
            std::unique_ptr< UnivariateData::Generator > rgenerator = response->generator();
            while(rgenerator->is_valid())
            {
                const UnivariateEvent* event = rgenerator->event();
                if(event && event->get_event() == ELEMENTARY)
                { curr += rgenerator->weight() * pow(static_cast< const DiscreteElementaryEvent* >(event)->get_value() - mean, 2) / (total * mean);}
                ++(*rgenerator);
            }
            unsigned int its = 0;
            NegativeBinomialRegression* nbinomial = new NegativeBinomialRegression(curr, CompleteScalarPredictor(*(data.get_explanatories()->get_sample_space())), *(_estimator->get_link()));
            std::unique_ptr< UnivariateConditionalDistributionEstimation > estimation;
            if(!lazy)
            { estimation = std::make_unique< NegativeBinomialRegressionX2Estimation  >(nbinomial, &data); }
            else
            { estimation = std::make_unique< LazyEstimation< NegativeBinomialRegression, DiscreteUnivariateConditionalDistributionEstimation > >(nbinomial); }
            _estimator->set_kappa(nbinomial->get_kappa());
            do
            {
                prev = curr;
                std::unique_ptr< UnivariateConditionalDistributionEstimation > _estimation =(*_estimator)(data, true);
                nbinomial->set_predictor(*(static_cast< const NegativeBinomialRegression* >(_estimation->get_estimated())->get_predictor()));
                if(!lazy)
                { static_cast< NegativeBinomialRegressionX2Estimation * >(estimation.get())->_iterations.push_back(nbinomial->get_kappa()); }
                curr = 0.;
                std::unique_ptr< UnivariateConditionalData::Generator > generator = data.generator();
                while(generator->is_valid())
                {
                    const UnivariateEvent* event = generator->response();
                    if(event && event->get_event() == ELEMENTARY)
                    {
                        mean = static_cast< const NegativeBinomialDistribution* >((*nbinomial)(*(generator->explanatories())))->get_mean();
                        curr += generator->weight() * pow(static_cast< const DiscreteElementaryEvent* >(event)->get_value() - mean, 2) / (total * mean * (1 + mean / prev));
                    }
                    ++(*generator);
                }
                curr = prev / curr;
                _estimator->set_kappa(curr);
                nbinomial->set_kappa(_estimator->get_kappa());
                ++its;
            } while(run(its, __impl::reldiff(prev, curr)));
            return estimation;
        }

        BinaryRegressionFisherEstimation::BinaryRegressionFisherEstimation(BinaryRegression const * estimated, UnivariateConditionalData const * data) : ScalarRegressionFisherEstimation< BinaryRegression, CategoricalUnivariateConditionalDistributionEstimation >(estimated, data)
        {}

        BinaryRegressionFisherEstimation::BinaryRegressionFisherEstimation(const BinaryRegressionFisherEstimation & estimation) : ScalarRegressionFisherEstimation< BinaryRegression, CategoricalUnivariateConditionalDistributionEstimation >(estimation)
        {}

        std::unique_ptr< UnivariateConditionalDistributionEstimation > BinaryRegressionFisherEstimation::copy() const
        { return std::make_unique< BinaryRegressionFisherEstimation >(*this); }

        BinaryRegressionFisherEstimation::Estimator::Estimator() : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, ScalarRegressionFisherEstimation< BinaryRegression, CategoricalUnivariateConditionalDistributionEstimation >::Estimator >()
        { _link = new BinaryCanonicalLink(); }
        
        BinaryRegressionFisherEstimation::Estimator::Estimator(const Estimator& estimator) : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, ScalarRegressionFisherEstimation< BinaryRegression, CategoricalUnivariateConditionalDistributionEstimation >::Estimator >(estimator)
        {}

        double BinaryRegressionFisherEstimation::Estimator::sigma_square(const double& mu) const
        { return mu * (1 - mu); }
        
        BinaryRegression * BinaryRegressionFisherEstimation::Estimator::build_estimated(const Eigen::VectorXd& beta, const UnivariateConditionalData& data) const
        {
            CompleteScalarPredictor predictor = CompleteScalarPredictor(*(data.get_explanatories()->get_sample_space()));
            predictor.set_beta(beta);
            const NominalSampleSpace* sample_space = static_cast< const NominalSampleSpace* >( data.get_response()->get_sample_space() );
            std::set< std::string > values = sample_space->get_values();
            if(values.size() != 2)
            { throw size_error("values", values.size(), 2); }
            std::set< std::string >::const_iterator it = values.cbegin();
            if(*it == sample_space->get_reference())
            { ++it; }
            return new BinaryRegression(*it, sample_space->get_reference(), predictor, *_link); 
        }
        
        Eigen::VectorXd BinaryRegressionFisherEstimation::Estimator::y_init(const UnivariateConditionalData& data) const
        {
            const UnivariateData* _data = data.get_response();
            Eigen::VectorXd y = Eigen::VectorXd::Zero(_data->size());
            std::unique_ptr< UnivariateData::Generator > generator = _data->generator();
            Index index = 0;
            while(generator->is_valid())
            {
                const UnivariateEvent* event = generator->event();
                if(event && event->get_event() == ELEMENTARY)
                {
                    if(static_cast< const CategoricalElementaryEvent* >(event)->get_value() != static_cast< const NominalSampleSpace* >(_data->get_sample_space())->get_reference())
                    { y(index) = 1; }
                }
                else
                { y(index) = std::numeric_limits< double >::quiet_NaN(); }
                ++(*generator);
                ++index;
            }
            return y;
        }



        CategoricalFisherInitialization::CategoricalFisherInitialization()
        {}
        
        CategoricalFisherInitialization::~CategoricalFisherInitialization()
        {}
        

        CategoricalFisherObservedInitialization::CategoricalFisherObservedInitialization()
        {}

        CategoricalFisherObservedInitialization::~CategoricalFisherObservedInitialization()
        {}

        void CategoricalFisherObservedInitialization::operator()(const UnivariateConditionalData& data, Eigen::VectorXd& beta, const VectorLink& link) const
        {
            if(data.get_response()->get_sample_space()->get_ordering() == ordering_type::NONE)
            {
                CategoricalUnivariateDistributionEstimation::Estimator estimator;
                Eigen::VectorXd observed_pi = static_cast< const NominalDistribution* >((estimator( *(data.get_response()) ))->get_estimated())->get_pi();
                std::set< std::string > categories = static_cast< const NominalDistribution* >((estimator( *(data.get_response()) ))->get_estimated())->get_values();
                std::string reference = static_cast< const NominalSampleSpace* >( data.get_response()->get_sample_space() )->get_reference();
                Eigen::VectorXd p = Eigen::VectorXd::Zero(observed_pi.size()-1);
                Index d = distance(categories.cbegin(), categories.find(reference));   
                if(d == p.size())
                { p = observed_pi.segment(0,p.size()); }
                else
                {
                    p.segment(0, d) = observed_pi.segment(0, d);
                    p.segment(d, p.size()-d) = observed_pi.segment(d+1, p.size()-d);
                }
                if(p.size() <= beta.size())
                { beta.segment(0, p.size()) = link.evaluate(p); }
                else
                { throw size_error("beta size init", p.size(), beta.size(), statiskit::size_error::size_type::superior); }
            }
            else if(data.get_response()->get_sample_space()->get_ordering() == ordering_type::TOTAL)
            {
                CategoricalUnivariateDistributionEstimation::Estimator estimator;
                Eigen::VectorXd observed_pi = static_cast< const OrdinalDistribution* >((estimator( *(data.get_response()) ))->get_estimated())->get_ordered_pi();
                if(observed_pi.size()-1 <= beta.size())
                { beta.segment(0, observed_pi.size()-1) = link.evaluate(observed_pi.segment(0,observed_pi.size()-1)); }
                else
                { throw size_error("beta size init", observed_pi.size()-1, beta.size(), statiskit::size_error::size_type::superior); }
            }
        }


        CategoricalFisherUniformInitialization::CategoricalFisherUniformInitialization()
        {}

        CategoricalFisherUniformInitialization::~CategoricalFisherUniformInitialization()
        {}

        void CategoricalFisherUniformInitialization::operator()(const UnivariateConditionalData& data, Eigen::VectorXd& beta, const VectorLink& link) const
        {
            Index J = static_cast< const CategoricalSampleSpace* >( data.get_response()->get_sample_space() )->get_cardinality();
            Eigen::VectorXd p = Eigen::VectorXd::Constant(J-1, 1./double(J)); 
            if(p.size() <= beta.size())
            { beta.segment(0, p.size()) = link.evaluate(p); }
            else
            { throw size_error("beta size init", p.size(), beta.size(), statiskit::size_error::size_type::superior); }
        }


        CategoricalFisherCustomInitialization::CategoricalFisherCustomInitialization()
        {}

        CategoricalFisherCustomInitialization::CategoricalFisherCustomInitialization(const Eigen::VectorXd& beta)
        { _beta = beta; }

        CategoricalFisherCustomInitialization::~CategoricalFisherCustomInitialization()
        {}

        void CategoricalFisherCustomInitialization::operator()(const UnivariateConditionalData& data, Eigen::VectorXd& beta, const VectorLink& link) const
        {
            if(beta.size() == _beta.size())
            { beta = _beta; }
        } 

        Eigen::VectorXd CategoricalFisherCustomInitialization::get_beta() const
        { return _beta; }

        void CategoricalFisherCustomInitialization::set_beta(const Eigen::VectorXd& beta)
        { _beta = beta; }       

        Design::Design()
        {}

        Design::~Design()
        {}

        CompleteDesign::CompleteDesign()
        {}

        CompleteDesign::~CompleteDesign()
        {}

        std::vector< Eigen::MatrixXd > CompleteDesign::Z_init(const UnivariateConditionalData& data) const
        {
            Index J = static_cast< const CategoricalSampleSpace* >( data.get_response()->get_sample_space() )->get_cardinality();
            const MultivariateData* _data = data.get_explanatories();
            const MultivariateSampleSpace* sample_space = _data->get_sample_space();
            Index p = sample_space->encode();
            std::vector< Eigen::MatrixXd > Z;
            Eigen::MatrixXd identity = Eigen::MatrixXd::Identity(J-1, J-1);
            std::unique_ptr< MultivariateData::Generator > generator = _data->generator();
            Eigen::MatrixXd Z_k = Eigen::MatrixXd::Identity(J-1, (J-1) * (1+p));
            while(generator->is_valid())
            {
                const MultivariateEvent* event = generator->event();
                if(event)
                {  
                   Z_k.block(0, J-1, J-1, (J-1) * p ) = Eigen::kroneckerProduct(identity, sample_space->encode(*event));
                   Z.push_back(Z_k);
               }
                else
                {
                    Z_k.block(0, J-1, J-1, (J-1) * p ) = std::numeric_limits< double >::quiet_NaN() * Eigen::MatrixXd::Ones(J-1, (J-1) * p);
                    Z.push_back(Z_k);
                }
                ++(*generator);
            }
            return Z;
        }

        Index CompleteDesign::beta_size(const UnivariateConditionalData& data) const
        {
            Index J = static_cast< const CategoricalSampleSpace* >( data.get_response()->get_sample_space() )->get_cardinality();
            Index p = data.get_explanatories()->get_sample_space()->encode(); 
            return (J-1)*(1+p);
        }

        VectorPredictor* CompleteDesign::build_predictor(const MultivariateSampleSpace& explanatory_space, const Index& dimension) const
        { return new CompleteVectorPredictor(explanatory_space, dimension); }


        ProportionalDesign::ProportionalDesign()
        {}

        ProportionalDesign::~ProportionalDesign()
        {}

        std::vector< Eigen::MatrixXd > ProportionalDesign::Z_init(const UnivariateConditionalData& data) const
        {
            Index J = static_cast< const CategoricalSampleSpace* >( data.get_response()->get_sample_space() )->get_cardinality();
            const MultivariateData* _data = data.get_explanatories();
            const MultivariateSampleSpace* sample_space = _data->get_sample_space();
            Index p = sample_space->encode();
            std::vector< Eigen::MatrixXd > Z;
            Eigen::MatrixXd identity = Eigen::MatrixXd::Identity(J-1, J-1);
            Eigen::VectorXd col_ones = Eigen::VectorXd::Ones(J-1);
            std::unique_ptr< MultivariateData::Generator > generator = _data->generator();
            Eigen::MatrixXd Z_k = Eigen::MatrixXd::Identity(J-1, J-1 + p);
            while(generator->is_valid())
            {
                const MultivariateEvent* event = generator->event();
                if(event)
                {
                    Z_k.block(0, J-1, J-1, p) = Eigen::kroneckerProduct(col_ones, sample_space->encode(*event));
                    Z.push_back(Z_k);
                }
                else
                { 
                    Z_k.block(0, J-1, J-1, p) = std::numeric_limits< double >::quiet_NaN() * Eigen::MatrixXd::Ones(J-1, p);
                    Z.push_back(Z_k);
                }
                ++(*generator);
            }
            return Z;            
        }

        Index ProportionalDesign::beta_size(const UnivariateConditionalData& data) const
        {
            Index J = static_cast< const CategoricalSampleSpace* >( data.get_response()->get_sample_space() )->get_cardinality();
            Index p = data.get_explanatories()->get_sample_space()->encode(); 
            return J-1+p;
        }

        VectorPredictor* ProportionalDesign::build_predictor(const MultivariateSampleSpace& explanatory_space, const Index& dimension) const
        { return new ProportionalVectorPredictor(explanatory_space, dimension); }


        ConstrainedDesign::ConstrainedDesign()
        {}

        ConstrainedDesign::ConstrainedDesign(const Eigen::MatrixXd& slope_constraint)
        { _slope_constraint = slope_constraint; }

        ConstrainedDesign::~ConstrainedDesign()
        {}

        std::vector< Eigen::MatrixXd > ConstrainedDesign::Z_init(const UnivariateConditionalData& data) const
        {
            Index J = static_cast< const CategoricalSampleSpace* >( data.get_response()->get_sample_space() )->get_cardinality();
            const MultivariateData* _data = data.get_explanatories();
            const MultivariateSampleSpace* explanatory_space = _data->get_sample_space();
            Index p = explanatory_space->encode();
            std::vector< Eigen::MatrixXd > Z;
            Eigen::MatrixXd identity = Eigen::MatrixXd::Identity(J-1, J-1);
            std::unique_ptr< MultivariateData::Generator > generator = _data->generator();
            Eigen::MatrixXd Z_k_complete = Eigen::MatrixXd::Identity(J-1, (J-1) * (1+p));       
            if(_intercept_constraint.size() == 0)
            { _intercept_constraint = Eigen::MatrixXd::Identity(J-1, J-1); }
            else
            {
                if(_intercept_constraint.rows() != J-1)
                { throw statiskit::size_error("intercept_constraint", _intercept_constraint.rows(), J-1 ); } 
                if(_intercept_constraint.cols() > _intercept_constraint.rows())
                { throw statiskit::size_error("intercept_constraint", _intercept_constraint.cols(), _intercept_constraint.rows(), statiskit::size_error::size_type::superior); } 
            }
            if(_slope_constraint.size() == 0)
            { _slope_constraint = Eigen::MatrixXd::Identity((J-1) * p, (J-1) * p); }
            else
            {
                if(_slope_constraint.rows() != ( p * (J-1) ) )
                { throw statiskit::size_error("slope_constraint", _slope_constraint.rows(),  p * (J-1) ); } 
                if(_slope_constraint.cols() > _slope_constraint.rows())
                { throw statiskit::size_error("slope_constraint", _slope_constraint.cols(), _slope_constraint.rows(), statiskit::size_error::size_type::superior); } 
            }
            while(generator->is_valid())
            {
                Eigen::MatrixXd Z_k  = Eigen::MatrixXd::Zero(J-1, _intercept_constraint.cols() + _slope_constraint.cols()) ;
                Z_k.block(0, 0, J-1, _intercept_constraint.cols()) = _intercept_constraint;
                const MultivariateEvent* event = generator->event();
                if(event)
                {
                    Z_k.block(0, J-1, J-1, _slope_constraint.cols()) = Eigen::kroneckerProduct(identity, explanatory_space->encode(*event)) * _slope_constraint;
                    Z.push_back(Z_k);
                }
                else
                { 
                    Z_k.block(0, J-1, J-1, _slope_constraint.cols()) = std::numeric_limits< double >::quiet_NaN() * Eigen::MatrixXd::Ones(J-1, _slope_constraint.cols());
                    Z.push_back(Z_k);
                }
                ++(*generator);
            }
            return Z;
        }

        Index ConstrainedDesign::beta_size(const UnivariateConditionalData& data) const
        { return _intercept_constraint.cols() + _slope_constraint.cols(); }

        VectorPredictor* ConstrainedDesign::build_predictor(const MultivariateSampleSpace& explanatory_space, const Index& dimension) const
        { return new ConstrainedVectorPredictor(explanatory_space,  _slope_constraint, _intercept_constraint); }

        const Eigen::MatrixXd& ConstrainedDesign::get_intercept_constraint() const
        { return _intercept_constraint; }

        void ConstrainedDesign::set_intercept_constraint(const Eigen::MatrixXd& intercept_constraint)
        { _intercept_constraint = intercept_constraint; }

        const Eigen::MatrixXd ConstrainedDesign::get_slope_constraint() const
        { return _slope_constraint; }

        void ConstrainedDesign::set_slope_constraint(const Eigen::MatrixXd& slope_constraint)
        { _slope_constraint = slope_constraint; }


        NominalRegressionFisherEstimation::NominalRegressionFisherEstimation () : CategoricalRegressionFisherEstimation< NominalRegression >()
        {}

        NominalRegressionFisherEstimation::NominalRegressionFisherEstimation (NominalRegression const * estimated, UnivariateConditionalData const * data) : CategoricalRegressionFisherEstimation< NominalRegression >(estimated, data)
        {}

        NominalRegressionFisherEstimation::NominalRegressionFisherEstimation (const NominalRegressionFisherEstimation & estimation) : CategoricalRegressionFisherEstimation< NominalRegression >(estimation)
        {}

        NominalRegressionFisherEstimation::Estimator::Estimator() : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, CategoricalRegressionFisherEstimation< NominalRegression >::Estimator >()
        { this->_link = new NominalCanonicalLink(); }

        NominalRegressionFisherEstimation::Estimator::Estimator(const Estimator& estimator) : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, CategoricalRegressionFisherEstimation< NominalRegression >::Estimator >(estimator)
        {}

        NominalRegression * NominalRegressionFisherEstimation::Estimator::build_estimated(const Eigen::VectorXd& beta, const MultivariateSampleSpace& explanatory_space, const UnivariateSampleSpace& response_space) const
        {
            const NominalSampleSpace& _response_space = static_cast< const NominalSampleSpace& >(response_space);
            VectorPredictor* predictor = this->_design->build_predictor(explanatory_space, _response_space.get_cardinality()-1);
            predictor->set_beta(beta);
            NominalRegression * res = new NominalRegression(_response_space.get_values(), *predictor, *(this->_link));
            res->set_reference(_response_space.get_reference());
            return res;
        }


        OrdinalRegressionFisherEstimation::OrdinalRegressionFisherEstimation () : CategoricalRegressionFisherEstimation< OrdinalRegression >()
        {}

        OrdinalRegressionFisherEstimation::OrdinalRegressionFisherEstimation (OrdinalRegression const * estimated, UnivariateConditionalData const * data) : CategoricalRegressionFisherEstimation< OrdinalRegression >(estimated, data)
        {}

        OrdinalRegressionFisherEstimation::OrdinalRegressionFisherEstimation (const OrdinalRegressionFisherEstimation & estimation) : CategoricalRegressionFisherEstimation< OrdinalRegression >(estimation)
        {}

        OrdinalRegressionFisherEstimation::Estimator::Estimator() : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, CategoricalRegressionFisherEstimation< OrdinalRegression >::Estimator >()
        { this->_link = new OrdinalCanonicalLink(); }

        OrdinalRegressionFisherEstimation::Estimator::Estimator(const Estimator& estimator) : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, CategoricalRegressionFisherEstimation< OrdinalRegression >::Estimator >(estimator)
        {}

        OrdinalRegression * OrdinalRegressionFisherEstimation::Estimator::build_estimated(const Eigen::VectorXd& beta, const MultivariateSampleSpace& explanatory_space, const UnivariateSampleSpace& response_space) const
        {
            const OrdinalSampleSpace& _response_space = static_cast< const OrdinalSampleSpace& >(response_space);
            VectorPredictor* predictor = this->_design->build_predictor(explanatory_space, _response_space.get_cardinality()-1);
            predictor->set_beta(beta);
            return new OrdinalRegression(_response_space.get_ordered(), *predictor, *(this->_link));
        }

        HierarchicalRegressionEstimation::HierarchicalRegressionEstimation() : ActiveEstimation< HierarchicalRegression, CategoricalUnivariateConditionalDistributionEstimation >()
        { _estimations.clear(); }

        HierarchicalRegressionEstimation::HierarchicalRegressionEstimation(HierarchicalRegression const * estimated, data_type const * data) : ActiveEstimation< HierarchicalRegression, CategoricalUnivariateConditionalDistributionEstimation >(estimated, data)
        { _estimations.clear(); }

        HierarchicalRegressionEstimation::HierarchicalRegressionEstimation(const HierarchicalRegressionEstimation& estimation) : ActiveEstimation< HierarchicalRegression, CategoricalUnivariateConditionalDistributionEstimation >(estimation)
        {
            _estimations.clear();
            //for(std::map< std::string, UnivariateConditionalDistributionEstimation* >::const_iterator it = estimation._estimations.cbegin(), it_end = estimation._estimations.cend(); it != it_end; ++it)            
            //{ _estimations[it->first] = static_cast< UnivariateConditionalDistributionEstimation* >(it->second->copy().release()); }
        }

        HierarchicalRegressionEstimation::~HierarchicalRegressionEstimation()
        {
            for(std::map< std::string, UnivariateConditionalDistributionEstimation* >::iterator it = _estimations.begin(), it_end = _estimations.end(); it != it_end; ++it)            
            {
                delete it->second;
                it->second = nullptr;
            }
            _estimations.clear();
        }

        std::unique_ptr< UnivariateConditionalDistributionEstimation > HierarchicalRegressionEstimation::copy() const
        { return std::make_unique< HierarchicalRegressionEstimation >(*this); }

        const UnivariateConditionalDistributionEstimation* HierarchicalRegressionEstimation::get_estimation(const std::string& value) const
        {
            std::map< std::string, UnivariateConditionalDistributionEstimation* >::const_iterator it = _estimations.find(value); 
            if(it != _estimations.cend())
            { return it->second; }
            else
            { throw in_set_error("value", value, __impl::keys(_estimations), false); }
        }

        HierarchicalRegressionEstimation::Estimator::Estimator()
        {
            _default_estimator = new NominalRegressionFisherEstimation::Estimator();
            _estimators.clear();
        }

        HierarchicalRegressionEstimation::Estimator::Estimator(const Estimator& estimator) : PolymorphicCopy< UnivariateConditionalDistributionEstimation::Estimator, Estimator, ActiveEstimation< HierarchicalRegression, UnivariateConditionalDistributionEstimation >::Estimator >(estimator)
        {
            if(estimator._default_estimator)
            { _default_estimator = static_cast< CategoricalUnivariateConditionalDistributionEstimation::Estimator* >(estimator._default_estimator->copy().release()); }
            else
            { _default_estimator = nullptr; }
            _estimators.clear();
            for(std::map< std::string, CategoricalUnivariateConditionalDistributionEstimation::Estimator* >::const_iterator it = estimator._estimators.cbegin(), it_end = estimator._estimators.cend(); it != it_end; ++it)
            { _estimators[it->first] = static_cast< CategoricalUnivariateConditionalDistributionEstimation::Estimator* >(it->second->copy().release()); }
        }

        HierarchicalRegressionEstimation::Estimator::~Estimator()
        {
            delete _default_estimator;
            _default_estimator = nullptr;
            for(std::map< std::string, CategoricalUnivariateConditionalDistributionEstimation::Estimator* >::iterator it = _estimators.begin(), it_end = _estimators.end(); it != it_end; ++it)            
            {
                delete it->second;
                it->second = nullptr;
            }
            _estimators.clear();
        }

        const CategoricalUnivariateConditionalDistributionEstimation::Estimator* HierarchicalRegressionEstimation::Estimator::get_default_estimator() const
        { return _default_estimator; }

        void HierarchicalRegressionEstimation::Estimator::set_default_estimator(const CategoricalUnivariateConditionalDistributionEstimation::Estimator* estimator)
        {
            if(_default_estimator)
            { delete _default_estimator; }
            if(estimator)
            { _default_estimator = static_cast< CategoricalUnivariateConditionalDistributionEstimation::Estimator* >(estimator->copy().release()); }
            else
            { _default_estimator = nullptr; }
        }

        const CategoricalUnivariateConditionalDistributionEstimation::Estimator* HierarchicalRegressionEstimation::Estimator::get_estimator(const std::string& value) const
        {
            std::map< std::string, CategoricalUnivariateConditionalDistributionEstimation::Estimator* >::const_iterator it = _estimators.find(value);
            if(it == _estimators.cend())
            { return nullptr; }
            else
            { return it->second; }
        }
                         
        void HierarchicalRegressionEstimation::Estimator::set_estimator(const std::string& value, const CategoricalUnivariateConditionalDistributionEstimation::Estimator* estimator)
        {
            if(estimator)
            {
                std::map< std::string, CategoricalUnivariateConditionalDistributionEstimation::Estimator* >::iterator it = _estimators.find(value);
                if(it == _estimators.end())
                { _estimators[value] = static_cast< CategoricalUnivariateConditionalDistributionEstimation::Estimator* >(estimator->copy().release()); }
                else
                { 
                    delete it->second;
                    it->second = static_cast< CategoricalUnivariateConditionalDistributionEstimation::Estimator* >(estimator->copy().release());
                }                    
            }
        }
                
        std::unique_ptr< UnivariateConditionalDistributionEstimation > HierarchicalRegressionEstimation::Estimator::operator() (const data_type& data, const bool& lazy) const
        {
            HierarchicalRegression* estimated = new HierarchicalRegression(*(static_cast< const HierarchicalSampleSpace* >(data.get_response()->get_sample_space())), *(data.get_explanatories()->get_sample_space()));
            HierarchicalRegressionEstimation* estimation = new HierarchicalRegressionEstimation(estimated, &data);

            const HierarchicalSampleSpace* hss = static_cast< const HierarchicalSampleSpace* >((data.get_response())->get_sample_space());
            for(HierarchicalSampleSpace::const_iterator it = hss->cbegin(), it_end = hss->cend(); it != it_end; ++it)
            {
                UnivariateConditionalData current_data = hss->split(it->first, data);
                if(_estimators.find(it->first) == _estimators.cend())
                { 
                    UnivariateConditionalDistributionEstimation* current_estimation = ((*_default_estimator)(current_data, lazy)).release();
                    estimation->_estimations[it->first] = current_estimation; 
                    estimated->set_regression(it->first, *(static_cast< const CategoricalUnivariateConditionalDistribution* >(current_estimation->get_estimated())));
                }
                else
                { estimation->_estimations[it->first] = ((*(_estimators.find(it->first)->second))(current_data, lazy)).release(); }
            }

            return std::unique_ptr< HierarchicalRegressionEstimation >(estimation);

        }               
    }
}
