#  Copyright 2021 Thomas Figueroa.
#  Distributed under the Boost Software License, Version 1.0.
#
#  See accompanying file LICENSE_1_0.txt or copy at
#  http://www.boost.org/LICENSE_1_0.txt

FetchContent_MakeAvailable(boost_tmp)

set(PUPPLE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/pupple)
set(TMP_UNITS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tmp_units)

set(PUPPLE_IXX
    ${PUPPLE_DIR}/meta_element.ixx
    # ${PUPPLE_DIR}/meta_map.ixx
    ${PUPPLE_DIR}/pupple.ixx
    ${PUPPLE_DIR}/pupple_algorithm.ixx
)

set(INTERNAL_UTILITIES_IXX
    ${CMAKE_CURRENT_SOURCE_DIR}/utility/three_way_impl.ixx
)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    foreach(tmp_module IN LISTS ${TMP_ALGO_IXX} ${TMP_MAIN_IXX} ${TMP_DETAIL_IXX} ${TMP_SEQ_IXX} ${PUPPLE_IXX} ${TMP_BASE_IXX})
        string(REGEX REPLACE "\/(.+)\.ixx" "\\1" module_file_name ${tmp_module})
        add_module(${module_file_name} ${tmp_module})
    endforeach()
endif()

add_library(nil_tmp
    STATIC
        ${PUPPLE_IXX}
        ${INTERNAL_UTILITIES_IXX}
)

target_link_libraries(nil_tmp PRIVATE boost_tmp)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    foreach(mod_name IN LISTS ${TMP_ALGO_IXX} ${TMP_MAIN_IXX} ${TMP_DETAIL_IXX} ${TMP_SEQ_IXX} ${PUPPLE_IXX} ${TMP_BASE_IXX})
        string(REGEX REPLACE "\/([A-z_]+)\.ixx" "\\1" module_without_ext ${mod_name})
        string(APPEND module_without_ext ".pcm")
        add_dependencies(nil_tmp ${module_without_ext})
    endforeach()
endif()

set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/base)
set(ALGO_DIR ${BASE_DIR}/algorithm)

set(BASE_ALGORITHM
    ${BASE_DIR}/bitfield.ixx
    ${ALGO_DIR}/bit_manip.ixx
    # ${BASE_DIR}/ccexpr.ixx
    ${ALGO_DIR}/charutils.ixx
    ${BASE_DIR}/static_vector.ixx
    ${ALGO_DIR}/stringutils.ixx
)

set(STRING_ALGORITHM
    ${ALGO_DIR}/strings/modifying.ixx
    ${ALGO_DIR}/strings/nonmodifying.ixx
    ${ALGO_DIR}/strings/unsafe.ixx
)

if(MSVC)
    set(WIN_ONLY_INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/unique_hnd.ixx
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/windef.ixx
        ${CMAKE_CURRENT_SOURCE_DIR}/windows/window_styles.ixx
    )
    set(WIN_HEADER_FILES ${CMAKE_SOURCE_DIR}/include/windows/main.h)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    foreach(algo_mod IN LISTS ${BASE_ALGORITHM} ${STRING_ALGORITHM})
        string(REGEX REPLACE "\/([A-z_]+)\.ixx" "\\1" algo_module_name ${algo_mod})
        add_module(${algo_module_name} ${algo_mod})
    endforeach()
endif()

add_library(nilbase
        ${BASE_ALGORITHM}
        ${STRING_ALGORITHM}
        ${WIN_ONLY_INTERFACE}
        ${WIN_HEADER_FILES}
)

if(MSVC)
    target_include_directories(nilbase PUBLIC ${CMAKE_SOURCE_DIR}/include/windows)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    foreach(algo_mod IN LISTS ${BASE_ALGORITHM} ${STRING_ALGORITHM})
        string(REGEX REPLACE "\/([A-z_]+)\.ixx" "\\1" algo_module_name ${algo_mod})
        string(APPEND algo_module_name ".pcm")
        add_dependencies(nilbase ${algo_module_name})
    endforeach()
endif()

target_link_libraries(nilbase
    PRIVATE
        boost_tmp
        nil_tmp
        fmt::fmt
)

set(TMP_UNITS_ENGINE_IXX
    ${TMP_UNITS_DIR}/engine/base.ixx
    ${TMP_UNITS_DIR}/engine/conversions.ixx
    ${TMP_UNITS_DIR}/engine/evaluators.ixx
    ${TMP_UNITS_DIR}/engine/operators.ixx
    ${TMP_UNITS_DIR}/engine/type_dispatcher.ixx
    ${TMP_UNITS_DIR}/engine/engine_tmp.ixx
)

set(TMP_UNITS_ANY_IXX
    ${TMP_UNITS_DIR}/units/anything.ixx
    ${TMP_UNITS_DIR}/units/tmp_all_units.ixx
    ${TMP_UNITS_DIR}/tmp_units.ixx
)

set(TMP_UNITS_BASE_SI_IXX
    ${TMP_UNITS_DIR}/units/SI/base/absorbed_dose.ixx
    ${TMP_UNITS_DIR}/units/SI/base/amount_of_substance.ixx
    ${TMP_UNITS_DIR}/units/SI/base/capacitance.ixx
    ${TMP_UNITS_DIR}/units/SI/base/catalytic_activity.ixx
    ${TMP_UNITS_DIR}/units/SI/base/conductance.ixx
    ${TMP_UNITS_DIR}/units/SI/base/electric_charge.ixx
    ${TMP_UNITS_DIR}/units/SI/base/electric_current.ixx
    ${TMP_UNITS_DIR}/units/SI/base/electromotive_force.ixx
    ${TMP_UNITS_DIR}/units/SI/base/energy.ixx
    ${TMP_UNITS_DIR}/units/SI/base/force.ixx
    ${TMP_UNITS_DIR}/units/SI/base/frequency.ixx
    ${TMP_UNITS_DIR}/units/SI/base/illuminance.ixx
    ${TMP_UNITS_DIR}/units/SI/base/inductance.ixx
    ${TMP_UNITS_DIR}/units/SI/base/length.ixx
    ${TMP_UNITS_DIR}/units/SI/base/luminous_flux.ixx
    ${TMP_UNITS_DIR}/units/SI/base/luminous_intensity.ixx
    ${TMP_UNITS_DIR}/units/SI/base/magnetic_flux_density.ixx
    ${TMP_UNITS_DIR}/units/SI/base/magnetic_flux.ixx
    ${TMP_UNITS_DIR}/units/SI/base/mass.ixx
    ${TMP_UNITS_DIR}/units/SI/base/plane_angle.ixx
    ${TMP_UNITS_DIR}/units/SI/base/power.ixx
    ${TMP_UNITS_DIR}/units/SI/base/pressure.ixx
    ${TMP_UNITS_DIR}/units/SI/base/radionuclide_activity.ixx
    ${TMP_UNITS_DIR}/units/SI/base/resistance.ixx
    ${TMP_UNITS_DIR}/units/SI/base/solid_angle.ixx
    ${TMP_UNITS_DIR}/units/SI/base/time.ixx
)

set(TMP_UNITS_BASE_SI_DERIVED_IXX
    ${TMP_UNITS_DIR}/units/SI/derived/absorbed_dose_rate.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/acceleration.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/action.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/angular_acceleration.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/angular_velocity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/area.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/catalytic_activity_concentration.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/catalytic_efficiency.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/concentration.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/current_density.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/density.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/dynamic_viscosity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/electric_charge_density.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/electric_field_strength.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/electric_flux.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/electrical_conductivity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/energy_flux_density.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/exposure.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/frequency_drift.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/heat_capacity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/jerk.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/linear_charge_density.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/luminous_efficacy.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/luminous_energy.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/luminous_exposure.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/magnetic_dipole_moment.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/magnetic_field_strength.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/magnetic_moment.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/magnetic_rigidity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/magnetic_susceptibility.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/magnetomotive_force.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/molality.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/molar_conductivity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/molar_energy.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/molar_heat_capacity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/molar_mass.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/molar_volume.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/moment_of_inertia.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/momentum.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/permeability.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/permittivity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/radiance.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/radiant_exposure.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/radiant_intensity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/resistivity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/snap.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/specific_heat_capacity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/specific_angular_momentum.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/specific_volume.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/spectral_irradiance.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/spectral_radiance.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/surface_charge_density.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/surface_density.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/temperature_gradient.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/thermal_conductivity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/velocity.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/volume.ixx
    ${TMP_UNITS_DIR}/units/SI/derived/yank.ixx
)

add_library(tmp_units_lib
    STATIC
        ${TMP_UNITS_ENGINE_IXX}
        ${TMP_UNITS_IXX}
        ${TMP_UNITS_ANY_IXX}
        ${TMP_UNITS_BASE_SI_IXX}
        ${TMP_UNITS_BASE_SI_DERIVED_IXX}
)

target_link_libraries(tmp_units_lib
    PRIVATE
        nil_tmp
        boost_tmp
)

add_subdirectory(geometry)
