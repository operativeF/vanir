#ifndef CRTP_HPP
#define CRTP_HPP

namespace boost::tmp::units
{
    template <typename T, template<typename> class crtpType>
    struct crtp
    {
        T& underlying() { return static_cast<T&>(*this); }
        T const& underlying() const { return static_cast<T const&>(*this); }
    };
} // namespace boost::tmp::units

#endif
