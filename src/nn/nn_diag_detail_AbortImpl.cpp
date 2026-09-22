#include <stdint.h>

namespace nn {
namespace diag {
namespace detail {

extern "C" void nn_diag_detail_LogImpl(const char* format, ...);

extern "C" void nn_diag_detail_AbortImpl(
    const char* format_base,
    const char* filename,
    const char* functionName,
    int32_t line
) {
    register const char* saved_filename = filename;

    static const char format1[] =
        "C:/Monolithsoft/BF2/prog/libs/monolib_mm/proj/windows/";

    static const char format2[] =
        "C:/Monolithsoft/BF2/prog/libs/monolib_mm/proj/windows/";

    nn_diag_detail_LogImpl(format1, functionName, line);

    nn_diag_detail_LogImpl(saved_filename);

    nn_diag_detail_LogImpl(format2);

#if defined(__aarch64__)
    __asm__ volatile("brk #0x3c0");
#endif
}

} // namespace detail
} // namespace diag
} // namespace nn