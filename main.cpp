//
// Created by 何召召 on 2021/9/18.
//

#include <string>
#include <iostream>
#include <langdetectpp/langdetectpp.h>
//#include <chrono>
#include <pybind11/pybind11.h>

using langdetectpp::Detector;
using langdetectpp::Language;
using namespace std;

//int language_det(string &text) {
//    auto start = std::chrono::system_clock::now();
//    auto detector = Detector::create();
//    Language lang = detector->detect(text);
////    return langdetectpp::stringOfLanguage(lang);
//    cout << langdetectpp::stringOfLanguage(lang) << std::endl;
//    auto end = std::chrono::system_clock::now();
//    std::chrono::duration<double> diff1 = end-start;
////    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
//    cout << "test1:" <<  diff1.count()  << std::endl;
//    lang = detector->detect(text);
//    cout << langdetectpp::stringOfLanguage(lang) << std::endl;
//    auto end2 = std::chrono::system_clock::now();
//    std::chrono::duration<double> diff = end2-start;
//    cout << "test2:" <<  diff.count()  << std::endl;
//}


class LanguageDet {
public:
    shared_ptr<Detector> m_detector;

    LanguageDet() {
        m_detector = Detector::create();
    }

    string language_det(const string &text) const {
//        auto start = std::chrono::system_clock::now();
        Language lang = this->m_detector->detect(text);
//        cout << langdetectpp::stringOfLanguage(lang) << std::endl;
//        auto end = std::chrono::system_clock::now();
//        chrono::duration<double> diff1 = end - start;
//        cout << "test1:" << diff1.count() << std::endl;
        return langdetectpp::stringOfLanguage(lang);
    }

};

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)
namespace py = pybind11;

PYBIND11_MODULE(language_det, m) {
    m.doc() = "this is a fastest c++ multi language detect function";

//m.def("language_det", &language_det, R"pbdoc(
//           multi language function
//        )pbdoc",  py::arg("text"));
    py::class_<LanguageDet>(m, "LanguageDet")
            .def(py::init<>())
            .def("language_det", &LanguageDet::language_det, R"pbdoc(
//           multi language function
//        )pbdoc", py::arg("text"));
//    py::class_<Pet>(m, "Pet")
//            .def(py::init<>())
//            .def_readwrite("name", &Pet::name);

#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}