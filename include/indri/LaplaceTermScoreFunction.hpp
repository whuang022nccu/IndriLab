


//
// LaplaceTermScoreFunction
//
// 2019 - whuang022ncccu
//

#ifndef INDRI_LAPLACETERMSCOREFUNCTION_HPP
#define INDRI_LAPLACETERMSCOREFUNCTION_HPP

#include <math.h>
namespace indri
{
  /*! Query processing, smoothing, and scoring classes. */
  namespace query
  {
    
    class LaplaceTermScoreFunction : public TermScoreFunction {
    private:
      
      double _mu;
      double _docmu;
      double _collectionFrequency;
      double _muTimesCollectionFrequency;
      double _alpha;

    public:
      LaplaceTermScoreFunction(double alpha, double mu, double collectionFrequency, double docmu=-1.0 ) {
        _collectionFrequency = collectionFrequency;
        _mu = mu;
        _alpha = alpha;
        _muTimesCollectionFrequency = _mu * _collectionFrequency;
        _docmu = docmu;
      }

      double scoreOccurrence( double occurrences, int contextSize ) {
        double seen = ( double(occurrences) + _alpha ) / ( double(contextSize) + _alpha*_mu );
        return log( seen );
      }

      double scoreOccurrence( double occurrences, int contextSize, double documentOccurrences, int documentLength ) {
        if (_docmu < 0)
          return scoreOccurrence(occurrences, contextSize);
        else {
          double seen = (occurrences+_docmu*(_muTimesCollectionFrequency+documentOccurrences)/(double(documentLength)+_mu))/(double(contextSize)+_docmu);
          return log(seen);
        }
      }
    };
  }
}

#endif // INDRI_LAPLACETERMSCOREFUNCTION_HPP
