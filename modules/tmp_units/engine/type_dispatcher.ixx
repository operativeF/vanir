//  Copyright 2019-2022 Thomas Figueroa.
//
//  Distributed under the Boost Software License, Version 1.0.
//
//  See accompanying file LICENSE_1_0.txt or copy an
//  http://www.boost.org/LICENSE_1_0.txt


export module Boost.TMP.Units.Engine.TypeDispatcher;

import Boost.TMP;

import Boost.TMP.Units.AllUnits;
import Boost.TMP.Units.Anything;
import Boost.TMP.Units.Engine.Base;

import std.core;

export namespace potato::units {
    using namespace boost::tmp;

    template <typename L, typename... Ls>
    struct dispatcher;

    // Unitless
    template <>
    struct dispatcher<list_<list_<>, list_<>>> {
        template <typename T, typename P>
        using f = P;
    };

    // absorbed_dose
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l>, list_<second_l, second_l>>> {
        template <typename T, typename P>
        using f = gray_impl<T, P>;
    };

    // amount_of_substance
    template <>
    struct dispatcher<list_<list_<mole_l>, list_<>>> {
        template <typename T, typename P>
        using f = mole_impl<T, P>;
    };

    // capacitance
    template <>
    struct dispatcher<list_<list_<second_l, second_l, second_l, second_l, ampere_l, ampere_l>, list_<meter_l, meter_l, gram_l>>> {
        template <typename T, typename P>
        using f = farad_impl<T, P>;
    };

    // catalytic_activity
    template <>
    struct dispatcher<list_<list_<mole_l>, list_<second_l>>> {
        template <typename T, typename P>
        using f = katal_impl<T, P>;
    };

    // conductance
    template <>
    struct dispatcher<list_<list_<second_l, second_l, second_l, ampere_l, ampere_l>, list_<meter_l, meter_l, gram_l>>> {
        template <typename T, typename P>
        using f = siemens_impl<T, P>;
    };

    // electric_charge
    template <>
    struct dispatcher<list_<list_<second_l, ampere_l>, list_<>>> {
        template <typename T, typename P>
        using f = coulomb_impl<T, P>;
    };

    // electric_current
    template <>
    struct dispatcher<list_<list_<ampere_l>, list_<>>> {
        template <typename T, typename P>
        using f = ampere_impl<T, P>;
    };

    // electromotive_force
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, second_l, ampere_l>>> {
        template <typename T, typename P>
        using f = volt_impl<T, P>;
    };

    // energy
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l>>> {
        template <typename T, typename P>
        using f = joule_impl<T, P>;
    };

    // force
    template <>
    struct dispatcher<list_<list_<gram_l, meter_l>, list_<second_l, second_l>>> {
        template <typename T, typename P>
        using f = newton_impl<T, P>;
    };

    // frequency
    template <>
    struct dispatcher<list_<list_<>, list_<second_l>>> {
        template <typename T, typename P>
        using f = hertz_impl<T, P>;
    };

    // illuminance
    template <>
    struct dispatcher<list_<list_<candela_l>, list_<meter_l, meter_l>>> {
        template <typename T, typename P>
        using f = lux_impl<T, P>;
    };

    // inductance
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, ampere_l, ampere_l>>> {
        template <typename T, typename P>
        using f = henry_impl<T, P>;
    };

    // length
    template <>
    struct dispatcher<list_<list_<meter_l>, list_<>>> {
        template <typename T, typename P>
        using f = meter_impl<T, P>;
    };

    // luminous_flux
    template <>
    struct dispatcher<list_<list_<candela_l, steradian_l>, list_<>>> {
        template <typename T, typename P>
        using f = lumen_impl<T, P>;
    };

    // luminous_intensity
    template <>
    struct dispatcher<list_<list_<candela_l>, list_<>>> {
        template <typename T, typename P>
        using f = candela_impl<T, P>;
    };

    // magnetic_flux
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, ampere_l>>> {
        template <typename T, typename P>
        using f = weber_impl<T, P>;
    };

    // magnetic_flux_density
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<second_l, second_l, ampere_l>>> {
        template <typename T, typename P>
        using f = tesla_impl<T, P>;
    };

    // mass
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<>>> {
        template <typename T, typename P>
        using f = gram_impl<T, P>;
    };

    // plane_angle
    template <>
    struct dispatcher<list_<list_<radian_l>, list_<>>> {
        template <typename T, typename P>
        using f = radian_impl<T, P>;
    };

    // power
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, second_l>>> {
        template <typename T, typename P>
        using f = watt_impl<T, P>;
    };

    // pressure
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<meter_l, second_l, second_l>>> {
        template <typename T, typename P>
        using f = pascal_impl<T, P>;
    };

    // radionuclide_activity
    template <>
    struct dispatcher<list_<list_<>, list_<decay_l>>> {
        template <typename T, typename P>
        using f = becquerel_impl<T, P>;
    };

    // resistance
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, second_l, ampere_l, ampere_l>>> {
        template <typename T, typename P>
        using f = ohm_impl<T, P>;
    };

    // solid_angle
    template <>
    struct dispatcher<list_<list_<steradian_l>, list_<>>> {
        template <typename T, typename P>
        using f = steradian_impl<T, P>;
    };

    // time
    template <>
    struct dispatcher<list_<list_<second_l>, list_<>>> {
        template <typename T, typename P>
        using f = second_impl<T, P>;
    };

    // absorbed_dose_rate
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l>, list_<second_l, second_l, second_l>>> {
        template <typename T, typename P>
        using f = gray_per_second_impl<T, P>;
    };

    // acceleration
    template <>
    struct dispatcher<list_<list_<meter_l>, list_<second_l, second_l>>> {
        template <typename T, typename P>
        using f = meter_per_square_second_impl<T, P>;
    };

    // action
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l>>> {
        template <typename T, typename P>
        using f = joule_second_impl<T, P>;
    };

    // angular_acceleration
    template <>
    struct dispatcher<list_<list_<radian_l>, list_<second_l, second_l>>> {
        template <typename T, typename P>
        using f = radian_per_square_second_impl<T, P>;
    };

    // angular_velocity
    template <>
    struct dispatcher<list_<list_<radian_l>, list_<second_l>>> {
        template <typename T, typename P>
        using f = radian_per_second_impl<T, P>;
    };

    // area
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l>, list_<>>> {
        template <typename T, typename P>
        using f = square_meter_impl<T, P>;
    };

    // catalytic_activity_concentration
    template <>
    struct dispatcher<list_<list_<mole_l>, list_<meter_l, meter_l, meter_l, second_l>>> {
        template <typename T, typename P>
        using f = katal_per_cubic_meter_impl<T, P>;
    };

    // catalytic_efficiency
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, meter_l>, list_<mole_l, second_l>>> {
        template <typename T, typename P>
        using f = cubic_meter_per_mole_second_impl<T, P>;
    };

    // concentration
    template <>
    struct dispatcher<list_<list_<mole_l>, list_<meter_l, meter_l, meter_l>>> {
        template <typename T, typename P>
        using f = mole_per_cubic_meter_impl<T, P>;
    };

    // current_density
    template <>
    struct dispatcher<list_<list_<ampere_l>, list_<meter_l, meter_l>>> {
        template <typename T, typename P>
        using f = ampere_per_square_meter_impl<T, P>;
    };

    // density
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<meter_l, meter_l, meter_l>>> {
        template <typename T, typename P>
        using f = gram_per_cubic_meter_impl<T, P>;
    };

    // dynamic_viscosity
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<meter_l, second_l>>> {
        template <typename T, typename P>
        using f = pascal_second_impl<T, P>;
    };

    // electric_charge_density
    template <>
    struct dispatcher<list_<list_<second_l, ampere_l>, list_<meter_l, meter_l, meter_l>>> {
        template <typename T, typename P>
        using f = coulomb_per_cubic_meter_impl<T, P>;
    };

    // electric_field_strength
    template <>
    struct dispatcher<list_<list_<meter_l, gram_l>, list_<second_l, second_l, second_l, ampere_l>>> {
        template <typename T, typename P>
        using f = volt_per_meter_impl<T, P>;
    };

    // electric_flux
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, meter_l, gram_l>, list_<second_l, second_l, second_l, ampere_l>>> {
        template <typename T, typename P>
        using f = volt_meter_impl<T, P>;
    };

    // electrical_conductivity
    template <>
    struct dispatcher<list_<list_<second_l, second_l, second_l, ampere_l, ampere_l>, list_<meter_l, meter_l, meter_l, gram_l>>> {
        template <typename T, typename P>
        using f = siemens_per_meter_impl<T, P>;
    };

    // energy_flux_density
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<second_l, second_l, second_l>>> {
        template <typename T, typename P>
        using f = joule_per_square_meter_second_impl<T, P>;
    };

    // exposure
    template <>
    struct dispatcher<list_<list_<second_l, ampere_l>, list_<gram_l>>> {
        template <typename T, typename P>
        using f = coulomb_per_kilogram_impl<T, P>;
    };

    // frequency_drift
    template <>
    struct dispatcher<list_<list_<>, list_<second_l, second_l>>> {
        template <typename T, typename P>
        using f = hertz_per_second_impl<T, P>;
    };

    // heat_capacity
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, kelvin_l>>> {
        template <typename T, typename P>
        using f = joule_per_kelvin_impl<T, P>;
    };

    // jerk
    template <>
    struct dispatcher<list_<list_<meter_l>, list_<second_l, second_l, second_l>>> {
        template <typename T, typename P>
        using f = meter_per_cubic_second_impl<T, P>;
    };

    // linear_charge_density
    template <>
    struct dispatcher<list_<list_<second_l, ampere_l>, list_<meter_l>>> {
        template <typename T, typename P>
        using f = coulomb_per_meter_impl<T, P>;
    };

    // luminous_efficacy
    template <>
    struct dispatcher<list_<list_<second_l, second_l, second_l, candela_l>, list_<meter_l, meter_l, gram_l>>> {
        template <typename T, typename P>
        using f = lumen_per_watt_impl<T, P>;
    };

    // luminous_energy
    template <>
    struct dispatcher<list_<list_<second_l, candela_l>, list_<>>> {
        template <typename T, typename P>
        using f = lumen_second_impl<T, P>;
    };

    // luminous_exposure
    template <>
    struct dispatcher<list_<list_<second_l, candela_l>, list_<meter_l, meter_l>>> {
        template <typename T, typename P>
        using f = lux_second_impl<T, P>;
    };

    // magnetic_dipole_moment
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, ampere_l>, list_<>>> {
        template <typename T, typename P>
        using f = joule_per_tesla_impl<T, P>;
    };

    // magnetic_field_strength
    template <>
    struct dispatcher<list_<list_<ampere_l>, list_<meter_l>>> {
        template <typename T, typename P>
        using f = ampere_per_meter_impl<T, P>;
    };

    // magnetic_moment
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, meter_l, gram_l>, list_<second_l, second_l, ampere_l>>> {
        template <typename T, typename P>
        using f = weber_meter_impl<T, P>;
    };

    // magnetic_rigidity
    template <>
    struct dispatcher<list_<list_<meter_l, gram_l>, list_<second_l, second_l, ampere_l>>> {
        template <typename T, typename P>
        using f = tesla_meter_impl<T, P>;
    };

    // magnetic_susceptibility
    template <>
    struct dispatcher<list_<list_<second_l, second_l, ampere_l, ampere_l>, list_<meter_l, gram_l>>> {
        template <typename T, typename P>
        using f = meter_per_henry_impl<T, P>;
    };

    // magnetomotive_force
    template <>
    struct dispatcher<list_<list_<ampere_l>, list_<radian_l>>> {
        template <typename T, typename P>
        using f = ampere_radian_impl<T, P>;
    };

    // molality
    template <>
    struct dispatcher<list_<list_<mole_l>, list_<gram_l>>> {
        template <typename T, typename P>
        using f = mole_per_kilogram_impl<T, P>;
    };

    // molar_conductivity
    template <>
    struct dispatcher<list_<list_<second_l, second_l, second_l, ampere_l, ampere_l>, list_<gram_l, mole_l>>> {
        template <typename T, typename P>
        using f = siemens_square_meter_per_mole_impl<T, P>;
    };

    // molar_energy
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, mole_l>>> {
        template <typename T, typename P>
        using f = joule_per_mole_impl<T, P>;
    };

    // molar_heat_capacity
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, mole_l, kelvin_l>>> {
        template <typename T, typename P>
        using f = joule_per_mole_kelvin_impl<T, P>;
    };

    // molar_mass
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<mole_l>>> {
        template <typename T, typename P>
        using f = gram_per_mole_impl<T, P>;
    };

    // molar_volume
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, meter_l>, list_<mole_l>>> {
        template <typename T, typename P>
        using f = cubic_meter_per_mole_impl<T, P>;
    };

    // moment_of_inertia
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<>>> {
        template <typename T, typename P>
        using f = gram_square_meter_impl<T, P>;
    };

    // momentum
    template <>
    struct dispatcher<list_<list_<meter_l, gram_l>, list_<second_l>>> {
        template <typename T, typename P>
        using f = newton_second_impl<T, P>;
    };

    // permeability
    template <>
    struct dispatcher<list_<list_<meter_l, gram_l>, list_<second_l, second_l, ampere_l, ampere_l>>> {
        template <typename T, typename P>
        using f = henry_per_meter_impl<T, P>;
    };

    // permittivity
    template <>
    struct dispatcher<list_<list_<second_l, second_l, second_l, second_l, ampere_l, ampere_l>, list_<meter_l, meter_l, meter_l, gram_l>>> {
        template <typename T, typename P>
        using f = farad_per_meter_impl<T, P>;
    };

    // radiance
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<second_l, second_l, second_l, steradian_l>>> {
        template <typename T, typename P>
        using f = watt_per_steradian_square_meter_impl<T, P>;
    };

    // radiant_exposure
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<second_l, second_l>>> {
        template <typename T, typename P>
        using f = joule_per_square_meter_impl<T, P>;
    };

    // radiant_intensity
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, gram_l>, list_<second_l, second_l, second_l, steradian_l>>> {
        template <typename T, typename P>
        using f = watt_per_steradian_impl<T, P>;
    };

    // resistivity
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, meter_l, gram_l>, list_<second_l, second_l, second_l, ampere_l, ampere_l>>> {
        template <typename T, typename P>
        using f = ohm_meter_impl<T, P>;
    };

    // snap
    template <>
    struct dispatcher<list_<list_<meter_l>, list_<second_l, second_l, second_l, second_l>>> {
        template <typename T, typename P>
        using f = meter_per_quartic_second_impl<T, P>;
    };

    // specific_heat_capacity
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l>, list_<second_l, second_l, kelvin_l>>> {
        template <typename T, typename P>
        using f = joule_per_kilogram_kelvin_impl<T, P>;
    };

    // specific_angular_momentum
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l>, list_<second_l>>> {
        template <typename T, typename P>
        using f = newton_meter_second_per_kilogram_impl<T, P>;
    };

    // specific_volume
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, meter_l>, list_<gram_l>>> {
        template <typename T, typename P>
        using f = cubic_meter_per_kilogram_impl<T, P>;
    };

    // spectral_irradiance
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<meter_l, second_l, second_l, second_l>>> {
        template <typename T, typename P>
        using f = watt_per_cubic_meter_impl<T, P>;
    };

    // spectral_radiance
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<meter_l, second_l, second_l, second_l, steradian_l>>> {
        template <typename T, typename P>
        using f = watt_per_steradian_cubic_meter_impl<T, P>;
    };

    // surface_charge_density
    template <>
    struct dispatcher<list_<list_<second_l, ampere_l>, list_<meter_l, meter_l>>> {
        template <typename T, typename P>
        using f = coulomb_per_square_meter_impl<T, P>;
    };

    // surface_density
    template <>
    struct dispatcher<list_<list_<gram_l>, list_<meter_l, meter_l>>> {
        template <typename T, typename P>
        using f = gram_per_square_meter_impl<T, P>;
    };

    // temperature_gradient
    template <>
    struct dispatcher<list_<list_<second_l, second_l, second_l, kelvin_l>, list_<meter_l, meter_l, gram_l>>> {
        template <typename T, typename P>
        using f = kelvin_per_watt_impl<T, P>;
    };

    // thermal_conductivity
    template <>
    struct dispatcher<list_<list_<meter_l, gram_l>, list_<second_l, second_l, second_l, kelvin_l>>> {
        template <typename T, typename P>
        using f = watt_per_meter_kelvin_impl<T, P>;
    };

    // velocity
    template <>
    struct dispatcher<list_<list_<meter_l>, list_<second_l>>> {
        template <typename T, typename P>
        using f = meter_per_second_impl<T, P>;
    };

    // volume
    template <>
    struct dispatcher<list_<list_<meter_l, meter_l, meter_l>, list_<>>> {
        template <typename T, typename P>
        using f = cubic_meter_impl<T, P>;
    };

    // yank
    template <>
    struct dispatcher<list_<list_<meter_l, gram_l>, list_<second_l, second_l, second_l>>> {
        template <typename T, typename P>
        using f = newton_per_second_impl<T, P>;
    };

    template <typename Anything>
    struct dispatcher<Anything> {
        template <typename T, typename P>
        using f = anything_impl<T, P, Anything>;
    };

    template <typename Anything>
    struct dispatcher<list_<Anything>> {
        template <typename T, typename P>
        using f = anything_impl<T, P, Anything>;
    };

} // namespace potato::units
