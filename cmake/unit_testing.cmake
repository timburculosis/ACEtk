#######################################################################
# Setup
#######################################################################

message( STATUS "Adding ACEtk unit testing" )
enable_testing()


#######################################################################
# Unit testing directories
#######################################################################

add_subdirectory( src/ACEtk/ContinuousEnergyTable/test )
add_subdirectory( src/ACEtk/DosimetryTable/test )
add_subdirectory( src/ACEtk/Table/Data/Parse/test )
add_subdirectory( src/ACEtk/Table/Data/test )
add_subdirectory( src/ACEtk/Table/Header/test )
add_subdirectory( src/ACEtk/Table/test )
add_subdirectory( src/ACEtk/block/PrincipalCrossSectionBlock/test )
add_subdirectory( src/ACEtk/block/ReactionNumberBlock/test )
add_subdirectory( src/ACEtk/block/ReactionQValueBlock/test )
add_subdirectory( src/ACEtk/block/FrameAndMultiplicityBlock/test )
add_subdirectory( src/ACEtk/block/CrossSectionData/test )
add_subdirectory( src/ACEtk/block/DosimetryCrossSectionData/test )
add_subdirectory( src/ACEtk/block/CrossSectionBlock/test )
add_subdirectory( src/ACEtk/block/TabulatedFissionMultiplicity/test )
add_subdirectory( src/ACEtk/block/DosimetryCrossSectionBlock/test )
add_subdirectory( src/ACEtk/block/SecondaryParticleTypeBlock/test )
add_subdirectory( src/ACEtk/block/EquiprobableAngularBins/test )
add_subdirectory( src/ACEtk/block/EquiprobableOutgoingEnergyBins/test )
add_subdirectory( src/ACEtk/block/TabulatedAngularDistribution/test )
add_subdirectory( src/ACEtk/block/IsotropicAngularDistribution/test )
add_subdirectory( src/ACEtk/block/AngularDistributionData/test )
add_subdirectory( src/ACEtk/block/AngularDistributionBlock/test )
add_subdirectory( src/ACEtk/block/LevelScatteringDistribution/test )
add_subdirectory( src/ACEtk/block/DiscretePhotonDistribution/test )
add_subdirectory( src/ACEtk/block/EquiprobableOutgoingEnergyBinData/test )
add_subdirectory( src/ACEtk/block/TabulatedEnergyDistribution/test )
add_subdirectory( src/ACEtk/block/OutgoingEnergyDistributionData/test )
add_subdirectory( src/ACEtk/block/TabulatedKalbachMannDistribution/test )
add_subdirectory( src/ACEtk/block/GeneralEvaporationSpectrum/test )
add_subdirectory( src/ACEtk/block/SimpleMaxwellianFissionSpectrum/test )
add_subdirectory( src/ACEtk/block/EvaporationSpectrum/test )
add_subdirectory( src/ACEtk/block/EnergyDependentWattSpectrum/test )
add_subdirectory( src/ACEtk/block/ParameterData/test )
add_subdirectory( src/ACEtk/block/KalbachMannDistributionData/test )
add_subdirectory( src/ACEtk/block/NBodyPhaseSpaceDistribution/test )
add_subdirectory( src/ACEtk/block/TwoBodyTransferDistribution/test )
add_subdirectory( src/ACEtk/block/TabulatedEnergyAngleDistribution/test )
add_subdirectory( src/ACEtk/block/EnergyAngleDistributionData/test )
add_subdirectory( src/ACEtk/block/AngleEnergyDistributionData/test )
add_subdirectory( src/ACEtk/block/TabulatedAngleEnergyDistribution/test )
add_subdirectory( src/ACEtk/block/MultiDistributionData/test )
add_subdirectory( src/ACEtk/block/DistributionProbability/test )
add_subdirectory( src/ACEtk/block/EnergyDistributionBlock/test )
add_subdirectory( src/ACEtk/block/PhotonProductionBlock/test )
add_subdirectory( src/ACEtk/block/TabulatedSecondaryParticleMultiplicity/test )
add_subdirectory( src/ACEtk/block/MultiplicityReactionNumberBlock/test )
add_subdirectory( src/ACEtk/details/verify/CDF/test )
add_subdirectory( src/ACEtk/details/verify/Positive/test )
add_subdirectory( src/ACEtk/details/verify/Sorted/test )
add_subdirectory( src/ACEtk/details/verify/StrictlyPositive/test )
add_subdirectory( src/ACEtk/details/verify/test )
add_subdirectory( src/ACEtk/interpretation/DEDX1/test )
add_subdirectory( src/ACEtk/interpretation/EL03/test )
add_subdirectory( src/ACEtk/interpretation/EPR/test )
add_subdirectory( src/ACEtk/interpretation/MP1/test )
add_subdirectory( src/ACEtk/XsdirEntry/test )
add_subdirectory( src/ACEtk/Xsdir/test )

#######################################################################
# python tests
#######################################################################

if( ACEtk.python )
  add_subdirectory( python/test )
endif()
