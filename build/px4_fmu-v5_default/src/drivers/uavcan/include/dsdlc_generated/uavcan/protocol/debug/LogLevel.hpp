/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/xj/007/007/Firmware/src/drivers/uavcan/libuavcan/dsdl/uavcan/protocol/debug/LogLevel.uavcan
 */

#ifndef UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_HPP_INCLUDED
#define UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# Log message severity
#

uint3 DEBUG    = 0
uint3 INFO     = 1
uint3 WARNING  = 2
uint3 ERROR    = 3
uint3 value
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.debug.LogLevel
saturated uint3 value
******************************************************************************/

#undef value
#undef DEBUG
#undef INFO
#undef WARNING
#undef ERROR

namespace uavcan
{
namespace protocol
{
namespace debug
{

template <int _tmpl>
struct UAVCAN_EXPORT LogLevel_
{
    typedef const LogLevel_<_tmpl>& ParameterType;
    typedef LogLevel_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > DEBUG;
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > INFO;
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > WARNING;
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > ERROR;
    };

    struct FieldTypes
    {
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > value;
    };

    enum
    {
        MinBitLen
            = FieldTypes::value::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::value::MaxBitLen
    };

    // Constants
    static const typename ::uavcan::StorageType< typename ConstantTypes::DEBUG >::Type DEBUG; // 0
    static const typename ::uavcan::StorageType< typename ConstantTypes::INFO >::Type INFO; // 1
    static const typename ::uavcan::StorageType< typename ConstantTypes::WARNING >::Type WARNING; // 2
    static const typename ::uavcan::StorageType< typename ConstantTypes::ERROR >::Type ERROR; // 3

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::value >::Type value;

    LogLevel_()
        : value()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<3 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    // This type has no default data type ID

    static const char* getDataTypeFullName()
    {
        return "uavcan.protocol.debug.LogLevel";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool LogLevel_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        value == rhs.value;
}

template <int _tmpl>
bool LogLevel_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(value, rhs.value);
}

template <int _tmpl>
int LogLevel_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::value::encode(self.value, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int LogLevel_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::value::decode(self.value, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature LogLevel_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x711BF141AF572346ULL);

    FieldTypes::value::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

template <int _tmpl>
const typename ::uavcan::StorageType< typename LogLevel_<_tmpl>::ConstantTypes::DEBUG >::Type
    LogLevel_<_tmpl>::DEBUG = 0U; // 0

template <int _tmpl>
const typename ::uavcan::StorageType< typename LogLevel_<_tmpl>::ConstantTypes::INFO >::Type
    LogLevel_<_tmpl>::INFO = 1U; // 1

template <int _tmpl>
const typename ::uavcan::StorageType< typename LogLevel_<_tmpl>::ConstantTypes::WARNING >::Type
    LogLevel_<_tmpl>::WARNING = 2U; // 2

template <int _tmpl>
const typename ::uavcan::StorageType< typename LogLevel_<_tmpl>::ConstantTypes::ERROR >::Type
    LogLevel_<_tmpl>::ERROR = 3U; // 3

/*
 * Final typedef
 */
typedef LogLevel_<0> LogLevel;

// No default registration

} // Namespace debug
} // Namespace protocol
} // Namespace uavcan

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::protocol::debug::LogLevel >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::protocol::debug::LogLevel::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::protocol::debug::LogLevel >::stream(Stream& s, ::uavcan::protocol::debug::LogLevel::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "value: ";
    YamlStreamer< ::uavcan::protocol::debug::LogLevel::FieldTypes::value >::stream(s, obj.value, level + 1);
}

}

namespace uavcan
{
namespace protocol
{
namespace debug
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::protocol::debug::LogLevel::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::protocol::debug::LogLevel >::stream(s, obj, 0);
    return s;
}

} // Namespace debug
} // Namespace protocol
} // Namespace uavcan

#endif // UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_HPP_INCLUDED