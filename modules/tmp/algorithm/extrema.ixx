//  Copyright 2018-2019 Odin Holmes.
//            2020-2021 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt

export module Boost.TMP.Algorithm.Extrema;

import Boost.TMP.Algorithm.FoldLeft;
import Boost.TMP.Base.Call;
import Boost.TMP.Base.Identity;
import Boost.TMP.Base.Lift;
import Boost.TMP.Detail.Dispatch;

export namespace boost::tmp {
		template <typename F, typename C = identity_>
		struct extrema_ {};

		namespace detail {
			constexpr int extrema_select(unsigned N) {
				return N == 0 ? 0 :
				                N < 2 ?
				                1 :
				                N < 4 ? 2 : N < 8 ? 4 : N < 16 ? 8 : N < 32 ? 16 : N < 64 ? 32 : 64;
			}

			template <unsigned N, template <typename...> class F, typename C>
			struct dispatch<N, extrema_<lift_<F>, C>> {
				template <typename T, typename... Ts>
				using f = typename dispatch<find_dispatch(sizeof...(Ts)),
				                            extrema_<lift_<F>, C>>::template f<Ts...>;
			};

			template <template <typename...> class F, typename C>
			struct dispatch<0, extrema_<lift_<F>, C>> {
				template <typename...>
				using f = typename dispatch<0, C>::template f<>;
			};

			template <template <typename...> class F, typename C>
			struct dispatch<1, extrema_<lift_<F>, C>> {
				template <typename T>
				using f = call_<fold_left_<lift_<F>>, T>;
			};

			template <template <typename...> class F, typename C>
			struct dispatch<2, extrema_<lift_<F>, C>> {
				template <typename T0, typename T1>
				using f = call_<fold_left_<lift_<F>>, T0, T1>;
			};
			template <template <typename...> class F, typename C>
			struct dispatch<4, extrema_<lift_<F>, C>> {
				template <typename T0, typename T1, typename T2, typename T3>
				using f = call_<fold_left_<lift_<F>>, T0, T1, T2, T3>;
			};
			template <template <typename...> class F, typename C>
			struct dispatch<8, extrema_<lift_<F>, C>> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename... Ts>
				using f = call_<fold_left_<lift_<F>>, T0, T1, T2, T3, T4, T5, T6, T7>;
			};
			template <template <typename...> class F, typename C>
			struct dispatch<16, extrema_<lift_<F>, C>> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename T12, typename T13, typename T14,
				          typename T15>
				using f = call_<fold_left_<lift_<F>>, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10,
				                T11, T12, T13, T14, T15>;
			};
			template <template <typename...> class F, typename C>
			struct dispatch<32, extrema_<lift_<F>, C>> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename T12, typename T13, typename T14,
				          typename T15, typename T16, typename T17, typename T18, typename T19,
				          typename T20, typename T21, typename T22, typename T23, typename T24,
				          typename T25, typename T26, typename T27, typename T28, typename T29,
				          typename T30, typename T31, typename... Ts>
				using f = call_<fold_left_<lift_<F>>, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10,
				                T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23,
				                T24, T25, T26, T27, T28, T29, T30, T31>;
			};
			template <template <typename...> class F, typename C>
			struct dispatch<64, extrema_<lift_<F>, C>> {
				template <typename T0, typename T1, typename T2, typename T3, typename T4,
				          typename T5, typename T6, typename T7, typename T8, typename T9,
				          typename T10, typename T11, typename T12, typename T13, typename T14,
				          typename T15, typename T16, typename T17, typename T18, typename T19,
				          typename T20, typename T21, typename T22, typename T23, typename T24,
				          typename T25, typename T26, typename T27, typename T28, typename T29,
				          typename T30, typename T31, typename T32, typename T33, typename T34,
				          typename T35, typename T36, typename T37, typename T38, typename T39,
				          typename T40, typename T41, typename T42, typename T43, typename T44,
				          typename T45, typename T46, typename T47, typename T48, typename T49,
				          typename T50, typename T51, typename T52, typename T53, typename T54,
				          typename T55, typename T56, typename T57, typename T58, typename T59,
				          typename T60, typename T61, typename T62, typename T63, typename... Ts>
				using f =
				        call_<fold_left_<lift_<F>>, T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10,
				              T11, T12, T13, T14, T15, T16, T17, T18, T19, T20, T21, T22, T23, T24,
				              T25, T26, T27, T28, T29, T30, T31, T32, T33, T34, T35, T36, T37, T38,
				              T39, T40, T41, T42, T43, T44, T45, T46, T47, T48, T49, T50, T51, T52,
				              T53, T54, T55, T56, T57, T58, T59, T60, T61, T62, T63>;
			};

			template <typename T, typename U>
			using lesser_v = int_<(T::value < U::value) ? T::value : U::value>;

			template <typename T, typename U>
			using greater_v = int_<!(T::value < U::value) ? T::value : U::value>;
		} // namespace detail

		template <typename C = identity_>
		using max_element_ = extrema_<lift_<detail::greater_v>, C>;

		template <typename C = identity_>
		using min_element_ = extrema_<lift_<detail::lesser_v>, C>;
} // export namespace boost::tmp
