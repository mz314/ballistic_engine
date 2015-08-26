#include "python/ui_defs.hpp"
#include "python/null_deleter.hpp"
#include "ui/rocket_context.hpp"
#include "ui/ui.hpp"
#include "ui/UIDocument.hpp"

boost::shared_ptr<UI> getSharedUIInstance() {
    return boost::shared_ptr<UI>(UI::getInstance(), NullDeleter());
}





//typedef ElementDocument* (*el_str)(const String& document_path);


BOOST_PYTHON_MODULE(BallisticUI) {    
    
    bp::class_<UI,  boost::shared_ptr<UI>, boost::noncopyable>("UI", bp::no_init)
    .def("get_instance", &getSharedUIInstance)
    .staticmethod("get_instance")
    .def("get_context", &UI::getContext, bp::return_value_policy<bp::reference_existing_object>())
    .def("add_document", &UI::addDocument, bp::return_value_policy<bp::reference_existing_object>())
    .def("get_document", &UI::getDocument, bp::return_value_policy<bp::reference_existing_object>())
    ;
    
    bp::class_<RC::ElementDocument, RC::ElementDocument *>("element_document", bp::no_init)
    ;
    
    bp::class_<UIDocument, UIDocument *>("ui_document", bp::no_init)
        .def("set_content_by_id", &UIDocument::setContentByID)
        .def("show", &UIDocument::show)
        .def("hide", &UIDocument::hide)
        .def("add_event_listener_id", &UIDocument::addEventListenerID)
    ;  
}

void init_ui() {
    initBallisticUI();
}
