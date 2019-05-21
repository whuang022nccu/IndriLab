
//
// LaplaceTermScoreFunction
//
// 2019 - whuang022ncccu
//

#ifndef INDRI_LAPLACETERMSCOREFUNCTION_HPP
#define INDRI_LAPLACETERMSCOREFUNCTION_HPP
#include <indri/QueryEnvironment.hpp>
#include <math.h>
#include <iostream>
namespace indri
{
  namespace query
  {
    
    class LaplaceTermScoreFunction : public TermScoreFunction {
    private:
      double _alpha;
      indri::api::QueryEnvironment *env;
    public:
      LaplaceTermScoreFunction(double alpha , const std::string& indexName) {
        _alpha = alpha;
	env = new indri::api::QueryEnvironment(); 
	env->addIndex(indexName);
      }

      double scoreOccurrence( double occurrences, int contextSize ) {
        double seen = ( double(occurrences) + _alpha ) / ( double(contextSize) + double(env->termCountUnique ()) );
        return log( seen );
      }
      double scoreOccurrence( double occurrences, int contextSize, double documentOccurrences, int documentLength ) {
         return scoreOccurrence( occurrences, contextSize );
      }
    };
  }
}

#endif // INDRI_LAPLACETERMSCOREFUNCTION_HPP
