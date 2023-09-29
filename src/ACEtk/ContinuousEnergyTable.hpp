#ifndef NJOY_ACETK_CONTINUOUSENERGYTABLE
#define NJOY_ACETK_CONTINUOUSENERGYTABLE

// system includes

// other includes
#include "ACEtk/Table.hpp"
#include "ACEtk/continuous/PrincipalCrossSectionBlock.hpp"
#include "ACEtk/continuous/FissionMultiplicityBlock.hpp"
#include "ACEtk/continuous/ReactionNumberBlock.hpp"
#include "ACEtk/continuous/ReactionQValueBlock.hpp"
#include "ACEtk/continuous/FrameAndMultiplicityBlock.hpp"
#include "ACEtk/continuous/CrossSectionBlock.hpp"
#include "ACEtk/continuous/AngularDistributionBlock.hpp"
#include "ACEtk/continuous/EnergyDistributionBlock.hpp"
#include "ACEtk/continuous/PhotonProductionBlock.hpp"
#include "ACEtk/continuous/MultiplicityReactionNumberBlock.hpp"
#include "ACEtk/continuous/PhotonProductionCrossSectionBlock.hpp"
#include "ACEtk/continuous/DelayedNeutronPrecursorBlock.hpp"
#include "ACEtk/continuous/ProbabilityTableBlock.hpp"
#include "ACEtk/continuous/SecondaryParticleTypeBlock.hpp"
#include "ACEtk/continuous/SecondaryParticleInformationBlock.hpp"
#include "ACEtk/continuous/SecondaryParticleLocatorBlock.hpp"
#include "ACEtk/continuous/SecondaryParticleProductionBlock.hpp"
#include "ACEtk/continuous/SecondaryParticleProductionCrossSectionBlock.hpp"
#include "ACEtk/continuous/SecondaryParticleAngularDistributionBlock.hpp"
#include "ACEtk/continuous/SecondaryParticleEnergyDistributionBlock.hpp"

namespace njoy {
namespace ACEtk {

/**
 *  @class
 *  @brief The continuous energy ACE table
 *
 *  The ContinuousEnergyTable class represents the ACE table for continuous
 *  energy data for incident neutrons and charged particles.
 */
class ContinuousEnergyTable : protected Table {

  /* fields */
  block::ESZ esz_;
  std::optional< block::NU > nu_;
  block::MTR mtr_;
  block::LQR lqr_;
  block::TYR tyr_;
  block::SIG sig_;
  block::AND and_;
  block::DLW dlw_;

  std::optional< block::GPD > gpd_;
  std::optional< block::MTRP > mtrp_;
  std::optional< block::SIGP > sigp_;
  std::optional< block::ANDP > andp_;
  std::optional< block::DLWP > dlwp_;
  std::optional< block::YP > yp_;

  std::optional< block::UNR > unr_;

  std::optional< block::NU > dnu_;
  std::optional< block::BDD > bdd_;
  std::optional< block::DNED > dned_;

  std::optional< block::PTYPE > ptype_;
  std::optional< block::NTRO > ntro_;
  std::optional< block::IXS > ixs_;
  std::vector< block::HPD > hpd_;
  std::vector< block::MTRH > mtrh_;
  std::vector< block::TYRH > tyrh_;
  std::vector< block::SIGH > sigh_;
  std::vector< block::ANDH > andh_;
  std::vector< block::DLWH > dlwh_;
  std::vector< block::YH > yh_;

  /* auxiliary functions */
  #include "ACEtk/ContinuousEnergyTable/src/generateBlocks.hpp"
  #include "ACEtk/ContinuousEnergyTable/src/generateData.hpp"
  #include "ACEtk/ContinuousEnergyTable/src/verifyType.hpp"

public:

  #include "ACEtk/ContinuousEnergyTable/src/ctor.hpp"

  using Table::header;
  using Table::data;
  using Table::print;

  //! @todo projectile() function
  //! @todo target() function

  /**
   *  @brief Return the full ZAID or SZAID of the table
   */
  const std::string& ZAID() const {

    return std::visit( [] ( const auto& header ) -> decltype(auto)
                          { return header.ZAID(); },
                       this->header() );
  }

  /**
   *  @brief Return the atomic weight ratio (with respect to the neutron mass)
   */
  double AWR() const {

    return std::visit( [] ( const auto& header ) -> decltype(auto)
                          { return header.AWR(); },
                       this->header() );
  }

  /**
   *  @brief Return the atomic weight ratio (with respect to the neutron mass)
   */
  double atomicWeightRatio() const { return this->AWR(); }

  /**
   *  @brief Return the temperature of the table
   */
  double TEMP() const {

    return std::visit( [] ( const auto& header ) -> decltype(auto)
                          { return header.TEMP(); },
                       this->header() );
  }

  /**
   *  @brief Return the temperature of the table
   */
  double temperature() const { return this->TEMP(); }

  /**
   *  @brief Return the date
   */
  const std::string& date() const {

    return std::visit( [] ( const auto& header ) -> decltype(auto)
                          { return header.date(); },
                       this->header() );
  }

  // NXS information

  /**
   *  @brief Return the total length of the XSS array
   */
  unsigned int length() const { return this->data().NXS(1); }

  /**
   *  @brief Return the ZA of the target
   */
  unsigned int ZA() const { return this->data().NXS(2); }

  /**
   *  @brief Return the number of energy points
   */
  unsigned int NES() const { return this->data().NXS(3); }

  /**
   *  @brief Return the number of energy points
   */
  unsigned int numberEnergyPoints() const { return this->NES(); }

  /**
   *  @brief Return the number of available reactions (excluding elastic)
   */
  unsigned int NTR() const { return this->data().NXS(4); }

  /**
   *  @brief Return the number of available reactions (excluding elastic)
   */
  unsigned int numberReactions() const { return this->NTR(); }

  /**
   *  @brief Return the total number of available reactions (including elastic)
   */
  unsigned int totalNumberReactions() const { return this->NTR() + 1; }

  /**
   *  @brief Return the number of reactions that produce the projectile
   *         (excluding elastic )
   */
  unsigned int NR() const { return this->data().NXS(5); }

  /**
   *  @brief Return the number of reactions that produce the projectile
   *         (excluding elastic )
   */
  unsigned int numberProjectileProductionReactions() const { return this->NR(); }

  /**
   *  @brief Return the number of reactions that produce photons
   */
  unsigned int NTRP() const { return this->data().NXS(6); }

  /**
   *  @brief Return the number of reactions that produce photons
   */
  unsigned int numberPhotonProductionReactions() const { return this->NTRP(); }

  /**
   *  @brief Return the number of secondary particle types (excluding the
   *         projectile)
   */
  unsigned int NTYPE() const { return this->data().NXS(7); }

  /**
   *  @brief Return the number of secondary particle types (excluding the
   *         projectile)
   */
  unsigned int numberAdditionalSecondaryParticleTypes() const { return this->NTYPE(); }

  /**
   *  @brief Return the number of delayed percursor families
   */
  unsigned int NPCR() const { return this->data().NXS(8); }

  /**
   *  @brief Return the number of delayed percursor families
   */
  unsigned int numberDelayedPrecursors() const { return this->NPCR(); }

  /**
   *  @brief Return the excited state of the target
   */
  unsigned int S() const { return this->data().NXS(9); }

  /**
   *  @brief Return the excited state of the target
   */
  unsigned int excitedState() const { return this->S(); }

  /**
   *  @brief Return the atom number of the target
   */
  unsigned int Z() const { return this->data().NXS(10); }

  /**
   *  @brief Return the atom number of the target
   */
  unsigned int atomNumber() const { return this->Z(); }

  /**
   *  @brief Return the mass number of the target
   */
  unsigned int A() const { return this->data().NXS(11); }

  /**
   *  @brief Return the mass number of the target
   */
  unsigned int massNumber() const { return this->A(); }

  // JXS information

  // XSS blocks

  /**
   *  @brief Return the principal cross section block
   */
  const block::ESZ& ESZ() const { return this->esz_; }

  /**
   *  @brief Return the principal cross section block
   */
  const block::ESZ& principalCrossSectionBlock() const { return this->ESZ(); }

  /**
   *  @brief Return the fission multiplicity block
   */
  const std::optional< block::NU >& NU() const { return this->nu_; }

  /**
   *  @brief Return the fission multiplicity block
   */
  const std::optional< block::NU >& fissionMultiplicityBlock() const {

    return this->NU();
  }

  /**
   *  @brief Return the reaction number block
   */
  const block::MTR& MTR() const { return this->mtr_; }

  /**
   *  @brief Return the reaction number block
   */
  const block::MTR& reactionNumberBlock() const { return this->MTR(); }

  /**
   *  @brief Return the reaction Q value block
   */
  const block::LQR& LQR() const { return this->lqr_; }

  /**
   *  @brief Return the reaction Q value block
   */
  const block::LQR& reactionQValueBlock() const { return this->LQR(); }

  /**
   *  @brief Return the reference frame and multiplicity block
   */
  const block::TYR& TYR() const { return this->tyr_; }

  /**
   *  @brief Return the reference frame and multiplicity block
   */
  const block::TYR& frameAndMultiplicityBlock() const { return this->TYR(); }

  /**
   *  @brief Return the cross section block
   */
  const block::SIG& SIG() const { return this->sig_; }

  /**
   *  @brief Return the cross section block
   */
  const block::SIG& crossSectionBlock() const { return this->SIG(); }

  /**
   *  @brief Return the angular distribution block
   */
  const block::AND& AND() const { return this->and_; }

  /**
   *  @brief Return the angular distribution block
   */
  const block::AND& angularDistributionBlock() const { return this->AND(); }

  /**
   *  @brief Return the energy distribution block
   */
  const block::DLW& DLW() const { return this->dlw_; }

  /**
   *  @brief Return the energy distribution block
   */
  const block::DLW& energyDistributionBlock() const { return this->DLW(); }

  /**
   *  @brief Return the photon production block
   */
  const std::optional< block::GPD >& GPD() const { return this->gpd_; }

  /**
   *  @brief Return the photon production block
   */
  const std::optional< block::GPD >& photonProductionBlock() const {

    return this->GPD();
  }

  /**
   *  @brief Return the photon production reaction number block
   */
  const std::optional< block::MTR >& MTRP() const { return this->mtrp_; }

  /**
   *  @brief Return the photon production reaction number block
   */
  const std::optional< block::MTR >& photonProductionReactionNumberBlock() const {

    return this->MTRP();
  }

  /**
   *  @brief Return the photon production cross section block
   */
  const std::optional< block::SIGP >& SIGP() const { return this->sigp_; }

  /**
   *  @brief Return the photon production cross section block
   */
  const std::optional< block::SIGP >& photonProductionCrossSectionBlock() const {

    return this->SIGP();
  }

  /**
   *  @brief Return the photon production angular distribution block
   */
  const std::optional< block::ANDP >& ANDP() const { return this->andp_; }

  /**
   *  @brief Return the photon production angular distribution block
   */
  const std::optional< block::ANDP >& photonProductionAngularDistributionBlock() const {

    return this->ANDP();
  }

  /**
   *  @brief Return the photon production energy distribution block
   */
  const std::optional< block::DLWP >& DLWP() const { return this->dlwp_; }

  /**
   *  @brief Return the photon production energy distribution block
   */
  const std::optional< block::DLWP >& photonProductionEnergyDistributionBlock() const {

    return this->DLWP();
  }

  /**
   *  @brief Return the photon multiplicity reaction number block
   */
  const std::optional< block::YP >& YP() const { return this->yp_; }

  /**
   *  @brief Return the photon multiplicity reaction number block
   */
  const std::optional< block::YP >& photonMultiplicityReactionNumberBlock() const {

    return this->YP();
  }

  /**
   *  @brief Return the unresoved probability table block
   */
  const std::optional< block::UNR >& UNR() const { return this->unr_; }

  /**
   *  @brief Return the unresoved probability table block
   */
  const std::optional< block::UNR >& probabilityTableBlock() const {

    return this->UNR();
  }

  /**
   *  @brief Return the delayed fission multiplicity block
   */
  const std::optional< block::NU >& DNU() const { return this->dnu_; }

  /**
   *  @brief Return the delayed fission multiplicity block
   */
  const std::optional< block::NU >& delayedFissionMultiplicityBlock() const {

    return this->DNU();
  }

  /**
   *  @brief Return the delayed neutron precursor block
   */
  const std::optional< block::BDD >& BDD() const { return this->bdd_; }

  /**
   *  @brief Return the delayed neutron precursor block
   */
  const std::optional< block::BDD >& delayedNeutronPrecursorBlock() const {

    return this->BDD();
  }

  /**
   *  @brief Return the delayed neutron energy distribution block
   */
  const std::optional< block::DNED >& DNED() const { return this->dned_; }

  /**
   *  @brief Return the delayed neutron energy distribution block
   */
  const std::optional< block::DNED >& delayedNeutronEnergyDistributionBlock() const {

    return this->DNED();
  }

  /**
   *  @brief Return the secondary particle type block
   */
  const std::optional< block::PTYPE >& PTYPE() const { return this->ptype_; }

  /**
   *  @brief Return the secondary particle type block
   */
  const std::optional< block::PTYPE >& secondaryParticleTypeBlock() const {

    return this->PTYPE();
  }

  /**
   *  @brief Return the secondary particle information block
   */
  const std::optional< block::NTRO >& NTRO() const { return this->ntro_; }

  /**
   *  @brief Return the secondary particle information block
   */
  const std::optional< block::NTRO >& secondaryParticleInformationBlock() const {

    return this->NTRO();
  }

  /**
   *  @brief Return the secondary particle locator block
   */
  const std::optional< block::IXS >& IXS() const { return this->ixs_; }

  /**
   *  @brief Return the secondary particle locator block
   */
  const std::optional< block::IXS >& secondaryParticleLocatorBlock() const {

    return this->IXS();
  }

  /**
   *  @brief Return the secondary particle production block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::HPD& HPD( std::size_t index ) const {

    return this->hpd_[ index - 1 ];
  }

  /**
   *  @brief Return secondary particle production block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::HPD& secondaryParticleProductionBlock( std::size_t index ) const {

    return this->HPD( index );
  }

  /**
   *  @brief Return the reaction number block for a secondary particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::MTRH& MTRH( std::size_t index ) const {

    return this->mtrh_[ index - 1 ];
  }

  /**
   *  @brief Return the reaction number block for a secondary particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::MTRH& secondaryParticleReactionNumberBlock( std::size_t index ) const {

    return this->MTRH( index );
  }

  /**
   *  @brief Return the multiplicity and reference frame block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::TYRH& TYRH( std::size_t index ) const {

    return this->tyrh_[ index - 1 ];
  }

  /**
   *  @brief Return the multiplicity and reference frame block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::TYRH& secondaryParticleFrameAndMultiplicityBlock( std::size_t index ) const {

    return this->TYRH( index );
  }

  /**
   *  @brief Return the production cross section block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::SIGH& SIGH( std::size_t index ) const {

    return this->sigh_[ index - 1 ];
  }

  /**
   *  @brief Return the production cross section block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::SIGH& secondaryParticleProductionCrossSectionBlock( std::size_t index ) const {

    return this->SIGH( index );
  }

  /**
   *  @brief Return the angular distribution block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::ANDH& ANDH( std::size_t index ) const {

    return this->andh_[ index - 1 ];
  }

  /**
   *  @brief Return the angular distribution block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::ANDH& secondaryParticleAngularDistributionBlock( std::size_t index ) const {

    return this->ANDH( index );
  }

  /**
   *  @brief Return the energy distribution block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::DLWH& DLWH( std::size_t index ) const {

    return this->dlwh_[ index - 1 ];
  }

  /**
   *  @brief Return the energy distribution block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::DLWH& secondaryParticleEnergyDistributionBlock( std::size_t index ) const {

    return this->DLWH( index );
  }

  /**
   *  @brief Return the multiplicity reaction number block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::YH& YH( std::size_t index ) const {

    return this->yh_[ index - 1 ];
  }

  /**
   *  @brief Return the multiplicity reaction number block for a secondary
   *         particle index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const block::YH& secondaryParticleMultiplicityReactionNumberBlock( std::size_t index ) const {

    return this->YH( index );
  }
};

} // ACEtk namespace
} // njoy namespace

#endif
