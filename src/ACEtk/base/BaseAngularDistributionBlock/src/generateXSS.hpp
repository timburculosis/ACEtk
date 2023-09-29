static std::vector< double >
generateXSS( std::vector< DistributionData >&& distributions ) {

  const auto nr = distributions.size();
  std::vector< double > xss( nr );
  std::size_t index = 0;
  for ( const auto& distribution : distributions ) {

    std::visit(

      utility::overload{

        [ &xss, index ] ( const block::FullyIsotropicDistribution& value ) {

          xss[index] = 0;
        },
        [ &xss, index ] ( const block::DistributionGivenElsewhere& value ) {

          xss[index] = -1;
        },
        [ &xss, index, nr ] ( const block::AngularDistributionData& value ) {

          xss[index] = xss.size() - nr + 1;

          // remake the internal xss array with the proper locators
          const block::AngularDistributionData temp(
                    std::move( value.distributions() ),
                    xss[index] );
          xss.insert( xss.end(), temp.begin(), temp.end() );
        }
      },
      distribution
    );
    ++index;
  }

  return xss;
}
