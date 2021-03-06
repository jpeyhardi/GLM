#include "_glm.h"



namespace autowig
{
    class Wrap_c62603d941d85899a63c49db84bf45d1 : public ::statiskit::PolymorphicCopy< struct ::statiskit::glm::Design, struct ::statiskit::glm::ProportionalDesign, struct ::statiskit::glm::Design >, public boost::python::wrapper< struct ::statiskit::PolymorphicCopy< struct ::statiskit::glm::Design, struct ::statiskit::glm::ProportionalDesign, struct ::statiskit::glm::Design > >
    {
        public:
            
            virtual class ::statiskit::glm::VectorPredictor * build_predictor(struct ::statiskit::MultivariateSampleSpace const & param_0, ::statiskit::Index const & param_1) const
            { return this->get_override("build_predictor")(param_0, param_1); }
                        
            virtual ::statiskit::Index  beta_size(class ::statiskit::UnivariateConditionalData const & param_0) const
            { return this->get_override("beta_size")(param_0); }
                        
            virtual class ::std::vector< class ::Eigen::Matrix< double, -1, -1, 0, -1, -1 >, class ::std::allocator< class ::Eigen::Matrix< double, -1, -1, 0, -1, -1 > > >  Z_init(class ::statiskit::UnivariateConditionalData const & param_0) const
            { return this->get_override("Z_init")(param_0); }
                        

        protected:
            

        private:
            

    };

}

#if defined(_MSC_VER)
    #if (_MSC_VER == 1900)
namespace boost
{
    template <> autowig::Wrap_c62603d941d85899a63c49db84bf45d1 const volatile * get_pointer<autowig::Wrap_c62603d941d85899a63c49db84bf45d1 const volatile >(autowig::Wrap_c62603d941d85899a63c49db84bf45d1 const volatile *c) { return c; }
    template <> struct ::statiskit::PolymorphicCopy< struct ::statiskit::glm::Design, struct ::statiskit::glm::ProportionalDesign, struct ::statiskit::glm::Design > const volatile * get_pointer<struct ::statiskit::PolymorphicCopy< struct ::statiskit::glm::Design, struct ::statiskit::glm::ProportionalDesign, struct ::statiskit::glm::Design > const volatile >(struct ::statiskit::PolymorphicCopy< struct ::statiskit::glm::Design, struct ::statiskit::glm::ProportionalDesign, struct ::statiskit::glm::Design > const volatile *c) { return c; }
}
    #endif
#endif



void wrapper_c62603d941d85899a63c49db84bf45d1()
{

    std::string name_fa414b05d29e5f4ea0b6d6cb5cf81b01 = boost::python::extract< std::string >(boost::python::scope().attr("__name__") + ".statiskit");
    boost::python::object module_fa414b05d29e5f4ea0b6d6cb5cf81b01(boost::python::handle<  >(boost::python::borrowed(PyImport_AddModule(name_fa414b05d29e5f4ea0b6d6cb5cf81b01.c_str()))));
    boost::python::scope().attr("statiskit") = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    boost::python::scope scope_fa414b05d29e5f4ea0b6d6cb5cf81b01 = module_fa414b05d29e5f4ea0b6d6cb5cf81b01;
    boost::python::class_< autowig::Wrap_c62603d941d85899a63c49db84bf45d1, autowig::Held< autowig::Wrap_c62603d941d85899a63c49db84bf45d1 >::Type, boost::python::bases< struct ::statiskit::glm::Design >, boost::noncopyable > class_c62603d941d85899a63c49db84bf45d1("_PolymorphicCopy_c62603d941d85899a63c49db84bf45d1", "", boost::python::no_init);

    if(autowig::Held< struct ::statiskit::PolymorphicCopy< struct ::statiskit::glm::Design, struct ::statiskit::glm::ProportionalDesign, struct ::statiskit::glm::Design > >::is_class)
    {
        boost::python::implicitly_convertible< autowig::Held< autowig::Wrap_c62603d941d85899a63c49db84bf45d1 >::Type, autowig::Held< struct ::statiskit::PolymorphicCopy< struct ::statiskit::glm::Design, struct ::statiskit::glm::ProportionalDesign, struct ::statiskit::glm::Design > >::Type >();
        boost::python::register_ptr_to_python< autowig::Held< struct ::statiskit::PolymorphicCopy< struct ::statiskit::glm::Design, struct ::statiskit::glm::ProportionalDesign, struct ::statiskit::glm::Design > >::Type >();
        boost::python::implicitly_convertible< autowig::Held< struct ::statiskit::PolymorphicCopy< struct ::statiskit::glm::Design, struct ::statiskit::glm::ProportionalDesign, struct ::statiskit::glm::Design > >::Type, autowig::Held< struct ::statiskit::glm::Design >::Type >();
    }

}