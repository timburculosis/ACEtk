// include Catch2
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
using Catch::Matchers::WithinRel;

// what we are testing
#include "ACEtk/continuous/TabulatedAngularDistributionWithProbability.hpp"

// other includes

// convenience typedefs
using namespace njoy::ACEtk;
using TabulatedAngularDistributionWithProbability = continuous::TabulatedAngularDistributionWithProbability;

std::vector< double > chunk();
void verifyChunk( const TabulatedAngularDistributionWithProbability& );

SCENARIO( "TabulatedAngularDistributionWithProbability" ) {

  GIVEN( "valid data for a TabulatedAngularDistributionWithProbability instance" ) {

    std::vector< double > xss = chunk();

    WHEN( "the data is given explicitly" ) {

      double energy = 2.1;
      double pdf = 0.5;
      double cdf = 0.75;
      int interpolation = 2;
      std::vector< double > cosines = { -1.0, 0.0, 1.0 };
      std::vector< double > pdfs = { 0.5, 0.5, 0.5 };
      std::vector< double > cdfs = { 0.0, 0.5, 1.0 };

      TabulatedAngularDistributionWithProbability chunk( energy, pdf, cdf,
                                                         interpolation,
                                                         std::move( cosines ),
                                                         std::move( pdfs ),
                                                         std::move( cdfs ) );

      THEN( "a TabulatedAngularDistributionWithProbability can be constructed and members can "
            "be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "the XSS array is correct" ) {

        auto xss_chunk = chunk.XSS();
        for ( unsigned int i = 0; i < chunk.length(); ++i ) {

          CHECK_THAT( xss[i], WithinRel( xss_chunk[i] ) );
        }
      } // THEN
    } // WHEN

    WHEN( "the data is defined by iterators" ) {

      double energy = 2.1;
      double pdf = 0.5;
      double cdf = 0.75;
      TabulatedAngularDistributionWithProbability chunk( energy, pdf, cdf,
                                                         xss.begin(), xss.end() );

      THEN( "a TabulatedAngularDistributionWithProbability can be constructed and members can be tested" ) {

        verifyChunk( chunk );
      } // THEN

      THEN( "the XSS array is correct" ) {

        auto xss_chunk = chunk.XSS();
        for ( unsigned int i = 0; i < chunk.length(); ++i ) {

          CHECK_THAT( xss[i], WithinRel( xss_chunk[i] ) );
        }
      } // THEN
    } // WHEN
  } // GIVEN
} // SCENARIO

std::vector< double > chunk() {

  return {                 2,                  3, -1.00000000000E+00,  0.00000000000E+00,
           1.00000000000E+00,  0.50000000000E+00,  0.50000000000E+00,  0.50000000000E+00,
           0.00000000000E+00,  0.50000000000E+00,  1.00000000000E+00 };
}

void verifyChunk( const TabulatedAngularDistributionWithProbability& chunk ) {

  CHECK( false == chunk.empty() );
  CHECK( 11 == chunk.length() );
  CHECK( "TabulatedAngularDistribution" == chunk.name() );

  CHECK_THAT( 2.1, WithinRel( chunk.energy() ) );
  CHECK_THAT( .5, WithinRel( chunk.probability() ) );
  CHECK_THAT( .75, WithinRel( chunk.cumulativeProbability() ) );
  CHECK( 2 == chunk.interpolation() );
  CHECK( 3 == chunk.numberCosines() );

  CHECK( 3 == chunk.cosines().size() );
  CHECK_THAT( -1., WithinRel( chunk.cosines().front() ) );
  CHECK_THAT( +1., WithinRel( chunk.cosines().back() ) );

  CHECK( 3 == chunk.pdf().size() );
  CHECK_THAT( .5, WithinRel( chunk.pdf().front() ) );
  CHECK_THAT( .5, WithinRel( chunk.pdf().back() ) );

  CHECK( 3 == chunk.cdf().size() );
  CHECK_THAT( 0., WithinRel( chunk.cdf().front() ) );
  CHECK_THAT( 1., WithinRel( chunk.cdf().back() ) );
}
