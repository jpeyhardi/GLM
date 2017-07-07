#include "_glm.h"



namespace autowig
{

}

#if defined(_MSC_VER)
    #if (_MSC_VER == 1900)
namespace boost
{
    template <> class ::statiskit::glm::NominalRegressionFisherEstimation< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > > const volatile * get_pointer<class ::statiskit::glm::NominalRegressionFisherEstimation< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > > const volatile >(class ::statiskit::glm::NominalRegressionFisherEstimation< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > > const volatile *c) { return c; }
}
    #endif
#endif



void wrapper_cf4a7dbf8a4752e89bc54a39fd2b3446()
{

    std::string name_fa414b05d29e5f4ea0b6d6cb5cf81b01 = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".statiskit");
    boost::python::object module_fa414b05d29e5f4ea0b6d6cb5cf81b01(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_fa414b05d29e5f4ea0b6d6cb5cf81b01.c_str()))));
    boost::python::scope().attr("statiskit") = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    boost::python::scope scope_fa414b05d29e5f4ea0b6d6cb5cf81b01 = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    std::string name_dfc470f00ed658a8838b0d698570f3bc = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".glm");
    boost::python::object module_dfc470f00ed658a8838b0d698570f3bc(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_dfc470f00ed658a8838b0d698570f3bc.c_str()))));
    boost::python::scope().attr("glm") = module_dfc470f00ed658a8838b0d698570f3bc;
    boost::python::scope scope_dfc470f00ed658a8838b0d698570f3bc = module_dfc470f00ed658a8838b0d698570f3bc;
    boost::python::class_< class ::statiskit::glm::NominalRegressionFisherEstimation< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > >, autowig::Held< class ::statiskit::glm::NominalRegressionFisherEstimation< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > > >::Type, boost::python::bases< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > > > class_cf4a7dbf8a4752e89bc54a39fd2b3446("_NominalRegressionFisherEstimation_cf4a7dbf8a4752e89bc54a39fd2b3446", "", boost::python::no_init);
    class_cf4a7dbf8a4752e89bc54a39fd2b3446.def(boost::python::init<  >(""));
    class_cf4a7dbf8a4752e89bc54a39fd2b3446.def(boost::python::init< class ::statiskit::glm::NominalRegression const *, class ::statiskit::UnivariateConditionalData const * >(""));
    class_cf4a7dbf8a4752e89bc54a39fd2b3446.def(boost::python::init< class ::statiskit::glm::NominalRegressionFisherEstimation< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > > const & >(""));

    if(autowig::Held< class ::statiskit::glm::NominalRegressionFisherEstimation< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > > >::is_class)
    {
        boost::python::implicitly_convertible< autowig::Held< class ::statiskit::glm::NominalRegressionFisherEstimation< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > > >::Type, autowig::Held< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::NominalRegression > >::Type >();
    }

}