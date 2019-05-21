


//
// JelinekMercerTermLaplaceScoreFunction
#ifndef INDRI_JELINEKMERCERLAPLACETERMSCOREFUNCTION_HPP
#define INDRI_JELINEKMERCERLAPLACETERMSCOREFUNCTION_HPP
#include <indri/QueryEnvironment.hpp>
#include <math.h>
namespace indri
{
  /// indri query processing and scoring components.
  namespace query
  {
    
    class JelinekMercerLaplaceTermScoreFunction : public TermScoreFunction {
    private:
      double _lambda;
      double _backgroundLambda;
      double _collectionFrequency;
      double _collectionComponent;
      double _oneLevelCollectionComponent;
      double _contextLambda;
      double _collectionLambda;
      double _documentLambda;
      double _foregroundLambda;
      indri::api::QueryEnvironment *env;
    public:
      JelinekMercerLaplaceTermScoreFunction( double collectionFrequency, double collectionLambda, double documentLambda  , const std::string& indexName ) {
        _contextLambda = (1 - collectionLambda - documentLambda);
        _collectionFrequency = collectionFrequency;
        _collectionLambda = collectionLambda;
        _documentLambda = documentLambda;
        _foregroundLambda = (1 - _collectionLambda);
        env = new indri::api::QueryEnvironment(); 
	env->addIndex(indexName);

        assert( _documentLambda >= 0.0 && _documentLambda <= 1.0 );
        assert( _collectionLambda >= 0.0 && _collectionLambda <= 1.0 );
        assert( _contextLambda >= 0.0 && _contextLambda <= 1.0 );
    
        _collectionComponent = _collectionLambda * _collectionFrequency;
      }

      double scoreOccurrence( double occurrences, int contextSize ) {
        double seen2 = ( double(occurrences) +1.0 ) / ( double(contextSize) + double(env->termCountUnique ()) );
        double contextFrequency = contextSize ? occurrences / double(contextSize) : 0.0;
        return (log( _foregroundLambda * contextFrequency + _collectionComponent )+log(seen2));
      }

      double scoreOccurrence( double occurrences, int contextSize, double documentOccurrences, int documentLength ) {
        double seen2 = ( double(occurrences) +1.0 ) / ( double(contextSize) + double(env->termCountUnique ()) );
        double contextFrequency = contextSize ? occurrences / double(contextSize) : 0.0;
        double documentFrequency = documentLength ? documentOccurrences / double(documentLength) : 0.0;
        return (log( _contextLambda * contextFrequency + _documentLambda * documentFrequency + _collectionComponent )+log(seen2));
      }
    };
  }
}

#endif // INDRI_JELINEKMERCERLAPLACETERMSCOREFUNCTION_HPP

