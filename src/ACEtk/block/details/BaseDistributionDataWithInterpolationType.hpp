#ifndef NJOY_ACETK_BLOCK_DETAILS_BASEDISTRIBUTIONDATAWITHINTERPOLATIONTYPE
#define NJOY_ACETK_BLOCK_DETAILS_BASEDISTRIBUTIONDATAWITHINTERPOLATIONTYPE

// system includes
#include <variant>

// other includes
#include "utility/overload.hpp"
#include "ACEtk/block/details/Base.hpp"
#include "ACEtk/block/details/ColumnData.hpp"
#include "ACEtk/block/InterpolationData.hpp"

namespace njoy {
namespace ACEtk {
namespace block {
namespace details {

/**
 *  @class
 *  @brief Base class for distribution data as a function of values using an
 *         interpolation type flag
 */
template< typename Derived, typename Distribution >
class BaseDistributionDataWithInterpolationType : protected details::Base {

  /* fields */
  std::size_t locb_;

protected:

  details::ColumnData values_;
  std::vector< Distribution > distributions_;

private:

  /* auxiliary functions */
  #include "ACEtk/block/details/BaseDistributionDataWithInterpolationType/src/verifyValueIndex.hpp"
  #include "ACEtk/block/details/BaseDistributionDataWithInterpolationType/src/generateBlocks.hpp"
  #include "ACEtk/block/details/BaseDistributionDataWithInterpolationType/src/verifySize.hpp"

protected:

  /* auxiliary functions */
  #include "ACEtk/block/details/BaseDistributionDataWithInterpolationType/src/generateXSS.hpp"

  /* constructor */
  #include "ACEtk/block/details/BaseDistributionDataWithInterpolationType/src/ctor.hpp"

public:

  /**
   *  @brief Return the interpolation flag
   */
  int interpolation() const { return this->IXSS( 1 ); }

  /**
   *  @brief Return the number of values in each column
   */
  std::size_t N() const { return this->values_.N(); }

  /**
   *  @brief Return the number of values in each column
   */
  std::size_t numberValues() const { return this->N(); }

  /**
   *  @brief Return the values for a given column index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] column    the column index (one-based)
   */
  auto values( std::size_t column ) const {

    return this->values_.column( column );
  }

  /**
   *  @brief Return the value for a given index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] column    the column index (one-based)
   *  @param[in] index     the index (one-based)
   */
  double value( std::size_t column, std::size_t index ) const {

    #ifndef NDEBUG
    this->verifyValueIndex( index );
    #endif
    return this->values_.value( column, index );
  }

  /**
   *  @brief Return the distribution locator for a value index
   *
   *  This locator is the value as stored in the XSS array.
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  int LOCC( std::size_t index ) const {

    return round( this->value( this->values_.NC(), index ) );
  }

  /**
   *  @brief Return the distribution locator for a value index
   *
   *  This locator is the value as stored in the XSS array.
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  int distributionLocator( std::size_t index ) const {

    return this->LOCC( index );
  }

  /**
   *  @brief Return the relative distribution locator for a value index
   *
   *  This is the locator relative to the beginning of the current distribution
   *  block.
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  std::size_t relativeDistributionLocator( std::size_t index ) const {

    const int locator = this->LOCC( index );
    return locator - this->locb_ + 1;
  }

  /**
   *  @brief Return the distributions
   */
  const std::vector< Distribution >& distributions() const {

    return this->distributions_;
  }

  /**
   *  @brief Return the distribution for a value index
   *
   *  When the index is out of range an std::out_of_range exception is thrown
   *  (debug mode only).
   *
   *  @param[in] index     the index (one-based)
   */
  const Distribution& distribution( std::size_t index ) const {

    #ifndef NDEBUG
    this->verifyValueIndex( index );
    #endif
    return this->distributions_[ index - 1 ];
  }

  using Base::empty;
  using Base::name;
  using Base::length;
  using Base::XSS;
  using Base::IXSS;
  using Base::begin;
  using Base::end;
};

} // details namespace
} // block namespace
} // ACEtk namespace
} // njoy namespace

#endif
