#include "_glm.h"



namespace autowig
{

}

#if defined(_MSC_VER)
    #if (_MSC_VER == 1900)
namespace boost
{
    template <> class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression > const volatile * get_pointer<class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression > const volatile >(class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression > const volatile *c) { return c; }
}
    #endif
#endif



void wrapper_4be05419f68050848635561b5842a32b()
{

    std::string name_fa414b05d29e5f4ea0b6d6cb5cf81b01 = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".statiskit");
    boost::python::object module_fa414b05d29e5f4ea0b6d6cb5cf81b01(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_fa414b05d29e5f4ea0b6d6cb5cf81b01.c_str()))));
    boost::python::scope().attr("statiskit") = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    boost::python::scope scope_fa414b05d29e5f4ea0b6d6cb5cf81b01 = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    std::string name_dfc470f00ed658a8838b0d698570f3bc = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".glm");
    boost::python::object module_dfc470f00ed658a8838b0d698570f3bc(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_dfc470f00ed658a8838b0d698570f3bc.c_str()))));
    boost::python::scope().attr("glm") = module_dfc470f00ed658a8838b0d698570f3bc;
    boost::python::scope scope_dfc470f00ed658a8838b0d698570f3bc = module_dfc470f00ed658a8838b0d698570f3bc;
    boost::python::class_< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression >, autowig::Held< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression > >::Type, boost::python::bases< class ::statiskit::glm::CategoricalRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression > > > class_4be05419f68050848635561b5842a32b("_ConstrainedRegressionFisherEstimation_4be05419f68050848635561b5842a32b", "", boost::python::no_init);
    class_4be05419f68050848635561b5842a32b.def(boost::python::init<  >(""));
    class_4be05419f68050848635561b5842a32b.def(boost::python::init< class ::statiskit::glm::OrdinalRegression const *, class ::statiskit::UnivariateConditionalData const * >(""));
    class_4be05419f68050848635561b5842a32b.def(boost::python::init< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression > const & >(""));

    if(autowig::Held< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression > >::is_class)
    {
        boost::python::implicitly_convertible< autowig::Held< class ::statiskit::glm::ConstrainedRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression > >::Type, autowig::Held< class ::statiskit::glm::CategoricalRegressionFisherEstimation< class ::statiskit::glm::OrdinalRegression > >::Type >();
    }

}