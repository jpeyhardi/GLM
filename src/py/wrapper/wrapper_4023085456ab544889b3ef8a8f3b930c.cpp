#include "_glm.h"



namespace autowig
{

}

#if defined(_MSC_VER)
    #if (_MSC_VER == 1900)
namespace boost
{
    template <> class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator const volatile * get_pointer<class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator const volatile >(class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator const volatile *c) { return c; }
}
    #endif
#endif



void wrapper_4023085456ab544889b3ef8a8f3b930c()
{

    std::string name_fa414b05d29e5f4ea0b6d6cb5cf81b01 = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".statiskit");
    boost::python::object module_fa414b05d29e5f4ea0b6d6cb5cf81b01(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_fa414b05d29e5f4ea0b6d6cb5cf81b01.c_str()))));
    boost::python::scope().attr("statiskit") = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    boost::python::scope scope_fa414b05d29e5f4ea0b6d6cb5cf81b01 = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    std::string name_dfc470f00ed658a8838b0d698570f3bc = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".glm");
    boost::python::object module_dfc470f00ed658a8838b0d698570f3bc(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_dfc470f00ed658a8838b0d698570f3bc.c_str()))));
    boost::python::scope().attr("glm") = module_dfc470f00ed658a8838b0d698570f3bc;
    boost::python::scope scope_dfc470f00ed658a8838b0d698570f3bc = module_dfc470f00ed658a8838b0d698570f3bc;
    std::string name_553bce355f285b778b4fc9f2e8800e96 = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + "._poisson_regression_fisher_estimation");
    boost::python::object module_553bce355f285b778b4fc9f2e8800e96(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_553bce355f285b778b4fc9f2e8800e96.c_str()))));
    boost::python::scope().attr("_poisson_regression_fisher_estimation") = module_553bce355f285b778b4fc9f2e8800e96;
    boost::python::scope scope_553bce355f285b778b4fc9f2e8800e96 = module_553bce355f285b778b4fc9f2e8800e96;
    boost::python::class_< class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator, autowig::Held< class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator >::Type, boost::python::bases< struct ::statiskit::PolymorphicCopy< struct ::statiskit::UnivariateConditionalDistributionEstimation::Estimator, class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator, class ::statiskit::glm::QuantitativeScalarRegressionFisherEstimation< class ::statiskit::glm::PoissonRegression, struct ::statiskit::DiscreteUnivariateConditionalDistributionEstimation >::Estimator > > > class_4023085456ab544889b3ef8a8f3b930c("Estimator", "", boost::python::no_init);
    class_4023085456ab544889b3ef8a8f3b930c.def(boost::python::init<  >(""));
    class_4023085456ab544889b3ef8a8f3b930c.def(boost::python::init< class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator const & >(""));

    if(autowig::Held< class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator >::is_class)
    {
        boost::python::implicitly_convertible< autowig::Held< class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator >::Type, autowig::Held< struct ::statiskit::PolymorphicCopy< struct ::statiskit::UnivariateConditionalDistributionEstimation::Estimator, class ::statiskit::glm::PoissonRegressionFisherEstimation::Estimator, class ::statiskit::glm::QuantitativeScalarRegressionFisherEstimation< class ::statiskit::glm::PoissonRegression, struct ::statiskit::DiscreteUnivariateConditionalDistributionEstimation >::Estimator > >::Type >();
    }

}