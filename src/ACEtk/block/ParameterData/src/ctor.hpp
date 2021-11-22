ParameterData() = default;

ParameterData( const ParameterData& ) = default;
ParameterData( ParameterData&& ) = default;

/**
 *  @brief Constructor
 *
 *  @param[in] boundaries      the interpolation range boundaries
 *  @param[in] interpolants    the interpolation types for each range
 *  @param[in] energies        the energy values
 *  @param[in] xs              the xs values
 */
ParameterData( std::vector< long >&& boundaries,
               std::vector< long >&& interpolants,
               std::vector< double >&& energies,
               std::vector< double >&& xs ) :
  BaseTabulatedData( "DLW::ParameterData",
                     std::move( boundaries ), std::move( interpolants ),
                     std::move( energies ), std::move( xs ) ) {}

/**
 *  @brief Constructor (linear interpolation is assumed)
 *
 *  @param[in] energies        the energy values
 *  @param[in] xs              the xs values
 */
ParameterData( std::vector< double >&& energies,
               std::vector< double >&& xs ) :
  ParameterData( {}, {}, std::move( energies ), std::move( xs ) ) {}

/**
 *  @brief Constructor
 *
 *  @param[in] sig     the begin iterator of the block in the XSS array
 *  @param[in] end     the end iterator of the block in the XSS array
 */
ParameterData( Iterator begin, Iterator end ) :
  BaseTabulatedData( "DLW::ParameterData", begin, end ) {}

ParameterData& operator=( const ParameterData& ) = default;
ParameterData& operator=( ParameterData&& ) = default;
