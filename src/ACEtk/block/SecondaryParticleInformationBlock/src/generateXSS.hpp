static std::vector< double > generateXSS( std::vector< unsigned int >&& numbers ) {

  std::vector< double > xss;
  auto ntype = numbers.size();
  xss.reserve( ntype );
  xss.insert( xss.end(), numbers.begin(), numbers.end() );
  return xss;
}
