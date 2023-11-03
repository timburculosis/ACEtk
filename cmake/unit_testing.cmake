#######################################################################
# Setup
#######################################################################

message( STATUS "Adding ACEtk unit testing" )
enable_testing()

function( add_cpp_test name source )

  set( test_name "ACEtk.${name}.test" )
  add_executable( ${test_name} ${source} )
  add_test( NAME ${test_name} COMMAND ${test_name} )
  target_link_libraries( ${test_name} PRIVATE ACEtk )
  target_link_libraries( ${test_name} PRIVATE Catch2::Catch2WithMain )

  file( GLOB resources "resources/*" )
  foreach( resource ${resources})
      file( COPY "${resource}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}" )
  endforeach()

endfunction()

#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/ACEtk/ContinuousEnergyTable/test )
add_subdirectory( src/ACEtk/DosimetryTable/test )
add_subdirectory( src/ACEtk/ThermalScatteringTable/test )
add_subdirectory( src/ACEtk/PhotoatomicTable/test )
add_subdirectory( src/ACEtk/PhotonuclearTable/test )
add_subdirectory( src/ACEtk/Table/Data/Parse/test )
add_subdirectory( src/ACEtk/Table/Data/test )
add_subdirectory( src/ACEtk/Table/Header/test )
add_subdirectory( src/ACEtk/Table/Header201/test )
add_subdirectory( src/ACEtk/Table/test )

add_subdirectory( src/ACEtk/continuous/PrincipalCrossSectionBlock/test )
add_subdirectory( src/ACEtk/continuous/ReactionNumberBlock/test )
add_subdirectory( src/ACEtk/continuous/ReactionQValueBlock/test )
add_subdirectory( src/ACEtk/continuous/FrameAndMultiplicityBlock/test )
add_subdirectory( src/ACEtk/continuous/CrossSectionData/test )
add_subdirectory( src/ACEtk/continuous/CrossSectionBlock/test )
add_subdirectory( src/ACEtk/continuous/TabulatedFissionMultiplicity/test )
add_subdirectory( src/ACEtk/continuous/FissionMultiplicityBlock/test )
add_subdirectory( src/ACEtk/continuous/EquiprobableAngularBins/test )
add_subdirectory( src/ACEtk/continuous/EquiprobableOutgoingEnergyBins/test )
add_subdirectory( src/ACEtk/continuous/TabulatedAngularDistribution/test )
add_subdirectory( src/ACEtk/continuous/TabulatedAngularDistributionWithProbability/test )
add_subdirectory( src/ACEtk/continuous/IsotropicAngularDistribution/test )
add_subdirectory( src/ACEtk/continuous/AngularDistributionData/test )
add_subdirectory( src/ACEtk/continuous/AngularDistributionBlock/test )
add_subdirectory( src/ACEtk/continuous/SecondaryParticleAngularDistributionBlock/test )
add_subdirectory( src/ACEtk/continuous/LevelScatteringDistribution/test )
add_subdirectory( src/ACEtk/continuous/DiscretePhotonDistribution/test )
add_subdirectory( src/ACEtk/continuous/EquiprobableOutgoingEnergyBinData/test )
add_subdirectory( src/ACEtk/continuous/TabulatedEnergyDistribution/test )
add_subdirectory( src/ACEtk/continuous/OutgoingEnergyDistributionData/test )
add_subdirectory( src/ACEtk/continuous/TabulatedKalbachMannDistribution/test )
add_subdirectory( src/ACEtk/continuous/GeneralEvaporationSpectrum/test )
add_subdirectory( src/ACEtk/continuous/SimpleMaxwellianFissionSpectrum/test )
add_subdirectory( src/ACEtk/continuous/EvaporationSpectrum/test )
add_subdirectory( src/ACEtk/continuous/EnergyDependentWattSpectrum/test )
add_subdirectory( src/ACEtk/continuous/ParameterData/test )
add_subdirectory( src/ACEtk/continuous/KalbachMannDistributionData/test )
add_subdirectory( src/ACEtk/continuous/NBodyPhaseSpaceDistribution/test )
add_subdirectory( src/ACEtk/continuous/TwoBodyTransferDistribution/test )
add_subdirectory( src/ACEtk/continuous/TabulatedEnergyAngleDistribution/test )
add_subdirectory( src/ACEtk/continuous/EnergyAngleDistributionData/test )
add_subdirectory( src/ACEtk/continuous/AngleEnergyDistributionData/test )
add_subdirectory( src/ACEtk/continuous/TabulatedAngleEnergyDistribution/test )
add_subdirectory( src/ACEtk/continuous/TabulatedMultiplicity/test )
add_subdirectory( src/ACEtk/continuous/MultiDistributionData/test )
add_subdirectory( src/ACEtk/continuous/DistributionProbability/test )
add_subdirectory( src/ACEtk/continuous/EnergyDistributionBlock/test )
add_subdirectory( src/ACEtk/continuous/SecondaryParticleEnergyDistributionBlock/test )
add_subdirectory( src/ACEtk/continuous/PhotonProductionBlock/test )
add_subdirectory( src/ACEtk/continuous/TabulatedSecondaryParticleMultiplicity/test )
add_subdirectory( src/ACEtk/continuous/PhotonProductionCrossSectionData/test )
add_subdirectory( src/ACEtk/continuous/PhotonProductionCrossSectionBlock/test )
add_subdirectory( src/ACEtk/continuous/MultiplicityReactionNumberBlock/test )
add_subdirectory( src/ACEtk/continuous/DelayedNeutronPrecursorData/test )
add_subdirectory( src/ACEtk/continuous/DelayedNeutronPrecursorBlock/test )
add_subdirectory( src/ACEtk/continuous/SecondaryParticleTypeBlock/test )
add_subdirectory( src/ACEtk/continuous/SecondaryParticleInformationBlock/test )
add_subdirectory( src/ACEtk/continuous/SecondaryParticleLocatorBlock/test )
add_subdirectory( src/ACEtk/continuous/SecondaryParticleProductionBlock/test )
add_subdirectory( src/ACEtk/continuous/SecondaryParticleProductionCrossSectionBlock/test )
add_subdirectory( src/ACEtk/continuous/ProbabilityTable/test )
add_subdirectory( src/ACEtk/continuous/ProbabilityTableBlock/test )

add_subdirectory( src/ACEtk/photoatomic/PrincipalCrossSectionBlock/test )
add_subdirectory( src/ACEtk/photoatomic/IncoherentScatteringFunctionBlock/test )
add_subdirectory( src/ACEtk/photoatomic/CoherentFormFactorBlock/test )
add_subdirectory( src/ACEtk/photoatomic/FluorescenceDataBlock/test )
add_subdirectory( src/ACEtk/photoatomic/HeatingNumbersBlock/test )
add_subdirectory( src/ACEtk/photoatomic/ComptonProfile/test )
add_subdirectory( src/ACEtk/photoatomic/ComptonProfileBlock/test )
add_subdirectory( src/ACEtk/photoatomic/PhotoelectricCrossSectionBlock/test )

add_subdirectory( src/ACEtk/dosimetry/CrossSectionData/test )
add_subdirectory( src/ACEtk/dosimetry/CrossSectionBlock/test )

add_subdirectory( src/ACEtk/electron/ElectronShellBlock/test )
add_subdirectory( src/ACEtk/electron/ElectronSubshellBlock/test )
add_subdirectory( src/ACEtk/electron/PrincipalCrossSectionBlock/test )
add_subdirectory( src/ACEtk/electron/ElasticCrossSectionBlock/test )
add_subdirectory( src/ACEtk/electron/ExcitationBlock/test )
add_subdirectory( src/ACEtk/electron/BremsstrahlungBlock/test )
add_subdirectory( src/ACEtk/electron/SubshellTransitionData/test )
add_subdirectory( src/ACEtk/electron/SubshellTransitionDataBlock/test )
add_subdirectory( src/ACEtk/electron/TabulatedAngularDistribution/test )
add_subdirectory( src/ACEtk/electron/ElasticAngularDistributionBlock/test )
add_subdirectory( src/ACEtk/electron/TabulatedEnergyDistribution/test )
add_subdirectory( src/ACEtk/electron/EnergyDistributionBlock/test )

add_subdirectory( src/ACEtk/thermal/CrossSectionBlock/test )
add_subdirectory( src/ACEtk/thermal/DiscreteCosines/test )
add_subdirectory( src/ACEtk/thermal/DiscreteCosinesWithProbability/test )
add_subdirectory( src/ACEtk/thermal/ElasticAngularDistributionBlock/test )
add_subdirectory( src/ACEtk/thermal/InelasticAngularDistributionBlock/test )

add_subdirectory( src/ACEtk/photonuclear/PrincipalCrossSectionBlock/test )
add_subdirectory( src/ACEtk/photonuclear/SecondaryParticleLocatorBlock/test )

add_subdirectory( src/ACEtk/XsdirEntry/test )
add_subdirectory( src/ACEtk/Xsdir/test )
