#include "_glm.h"



namespace autowig
{

}

#if defined(_MSC_VER)
    #if (_MSC_VER == 1900)
namespace boost
{
    template <> class ::statiskit::glm::ScalarRegressionFisherEstimation< class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation > const volatile * get_pointer<class ::statiskit::glm::ScalarRegressionFisherEstimation< class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation > const volatile >(class ::statiskit::glm::ScalarRegressionFisherEstimation< class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation > const volatile *c) { return c; }
}
    #endif
#endif



void wrapper_c0df82ab769f533ca406fc06b25adba1()
{

    std::string name_fa414b05d29e5f4ea0b6d6cb5cf81b01 = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".statiskit");
    boost::python::object module_fa414b05d29e5f4ea0b6d6cb5cf81b01(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_fa414b05d29e5f4ea0b6d6cb5cf81b01.c_str()))));
    boost::python::scope().attr("statiskit") = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    boost::python::scope scope_fa414b05d29e5f4ea0b6d6cb5cf81b01 = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    std::string name_dfc470f00ed658a8838b0d698570f3bc = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".glm");
    boost::python::object module_dfc470f00ed658a8838b0d698570f3bc(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_dfc470f00ed658a8838b0d698570f3bc.c_str()))));
    boost::python::scope().attr("glm") = module_dfc470f00ed658a8838b0d698570f3bc;
    boost::python::scope scope_dfc470f00ed658a8838b0d698570f3bc = module_dfc470f00ed658a8838b0d698570f3bc;
    boost::python::class_< class ::statiskit::glm::ScalarRegressionFisherEstimation< class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation >, autowig::Held< class ::statiskit::glm::ScalarRegressionFisherEstimation< class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation > >::Type, boost::python::bases< struct ::statiskit::OptimizationEstimation< class ::Eigen::Matrix< double, -1, 1, 0, -1, 1 >, class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation > > > class_c0df82ab769f533ca406fc06b25adba1("_ScalarRegressionFisherEstimation_c0df82ab769f533ca406fc06b25adba1", "", boost::python::no_init);
    class_c0df82ab769f533ca406fc06b25adba1.def(boost::python::init<  >(""));
    class_c0df82ab769f533ca406fc06b25adba1.def(boost::python::init< class ::statiskit::glm::BinaryRegression const *, class ::statiskit::UnivariateConditionalData const * >(""));
    class_c0df82ab769f533ca406fc06b25adba1.def(boost::python::init< class ::statiskit::glm::ScalarRegressionFisherEstimation< class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation > const & >(""));

    if(autowig::Held< class ::statiskit::glm::ScalarRegressionFisherEstimation< class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation > >::is_class)
    {
        boost::python::implicitly_convertible< autowig::Held< class ::statiskit::glm::ScalarRegressionFisherEstimation< class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation > >::Type, autowig::Held< struct ::statiskit::OptimizationEstimation< class ::Eigen::Matrix< double, -1, 1, 0, -1, 1 >, class ::statiskit::glm::BinaryRegression, struct ::statiskit::CategoricalUnivariateConditionalDistributionEstimation > >::Type >();
    }

}