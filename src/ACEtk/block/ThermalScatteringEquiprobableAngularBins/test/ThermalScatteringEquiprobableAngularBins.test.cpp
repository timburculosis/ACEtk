#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "ACEtk/block/ThermalScatteringEquiprobableAngularBins.hpp"

// other includes

// convenience typedefs
using namespace njoy::ACEtk;
using ThermalScatteringEquiprobableAngularBins = block::ThermalScatteringEquiprobableAngularBins;

std::vector< double > chunk();
void verifyChunk( const ThermalScatteringEquiprobableAngularBins& );

SCENARIO( "ThermalScatteringEquiprobableAngularBins" ) {

  GIVEN( "valid data for a ThermalScatteringEquiprobableAngularBins instance" ) {

    std::vector< double > xss = chunk();

    WHEN( "the data is given explicitly" ) {

      double energy = 2.1;
      std::vector< double > cosines = {

        -1.0, -0.9, -0.8, -0.7, -0.6, -0.5, -0.3, -0.2, -0.1, 0.0,
        0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5,
        0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.925, 0.95,
        0.9625, 0.975, 1.0
      };

      ThermalScatteringEquiprobableAngularBins chunk( energy,
                                                      std::move( cosines ) );

      THEN( "a ThermalScatteringEquiprobableAngularBins can be constructed "
            "and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "the XSS array is correct" ) {

        auto xss_chunk = chunk.XSS();
        for ( unsigned int i = 0; i < chunk.length(); ++i ) {

          CHECK( xss[i] == Approx( xss_chunk[i] ) );
        }
      } // THEN
    } // WHEN

    WHEN( "the data is defined by iterators" ) {

      ThermalScatteringEquiprobableAngularBins chunk( 32, xss.begin(), xss.end() );

      THEN( "a ThermalScatteringEquiprobableAngularBins can be constructed "
            "and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "the XSS array is correct" ) {

        auto xss_chunk = chunk.XSS();
        for ( unsigned int i = 0; i < chunk.length(); ++i ) {

          CHECK( xss[i] == Approx( xss_chunk[i] ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::vector< double > chunk() {

  return {

     2.10000000000E+00,
    -1.00000000000E+00, -0.90000000000E+00, -0.80000000000E+00, -0.70000000000E+00,
    -0.60000000000E+00, -0.50000000000E+00, -0.30000000000E+00, -0.20000000000E+00,
    -0.10000000000E+00,  0.00000000000E+00,  0.05000000000E+00,  0.10000000000E+00,
     0.15000000000E+00,  0.20000000000E+00,  0.25000000000E+00,  0.30000000000E+00,
     0.35000000000E+00,  0.40000000000E+00,  0.45000000000E+00,  0.50000000000E+00,
     0.55000000000E+00,  0.60000000000E+00,  0.65000000000E+00,  0.70000000000E+00,
     0.75000000000E+00,  0.80000000000E+00,  0.85000000000E+00,  0.90000000000E+00,
     0.92500000000E+00,  0.95000000000E+00,  0.96250000000E+00,  0.97500000000E+00,
     1.00000000000E+00
  };
}

void verifyChunk( const ThermalScatteringEquiprobableAngularBins& chunk ) {

  CHECK( false == chunk.empty() );
  CHECK( 34 == chunk.length() );
  CHECK( "ThermalScatteringEquiprobableAngularBins" == chunk.name() );

  CHECK( 2.1 == Approx( chunk.energy() ) );
  CHECK( 32 == chunk.numberBins() );

  CHECK( 33 == chunk.cosines().size() );
  CHECK( -1. == Approx( chunk.cosines().front() ) );
  CHECK( +1. == Approx( chunk.cosines().back() ) );
}
