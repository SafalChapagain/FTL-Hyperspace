#ifndef EVENTENUMS_H
#define EVENTENUMS_H
//NOTE: This approach has a limit of 256 enum values.
#ifndef SWIG
    #define BOOST_PP_LIMIT_TUPLE 256
    #include <boost/preprocessor/seq/for_each.hpp>
    #include <boost/preprocessor/stringize.hpp>
    #include <boost/preprocessor/variadic/to_seq.hpp>
    #define STRINGIZE_FOR_EACH(_, __, arg) BOOST_PP_STRINGIZE(arg) ,
    #define NAMED_ENUM(enumName, ...) \
    enum enumName { \
        __VA_ARGS__ \
    }; \
    static const char* GetName(enumName e) { \
        static const char* names[] = {BOOST_PP_SEQ_FOR_EACH(STRINGIZE_FOR_EACH, ~, BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__))}; \
        return names[e]; \
    };
#else //#ifdef SWIG
    %define NAMED_ENUM(enumName, ...)
        enum enumName {
            __VA_ARGS__
        };
    %enddef //NAMED_ENUM
#endif //#ifdef SWIG

#endif //EVENTENUMS_H
