#pragma once

#include <map>
#include <QtSql>

using namespace std;

namespace NLP
{

    const QString DB_PATH = "../../en_db.sqlite";
        // Depending on where the build folder is
        // default NLP/Unit-Testing/build....

    // word tag? there are more, see .dat for list of them
    enum WordType {
        others = 0,
        adjective , adverb        , conjunction , dative,
        noun      , interjections , imperative  ,
        particple , preposition   , pronoun     , plural , singular,
        verb      , transitive, intransitive, interrogative, object,

        IGNORETHIS
    };

    static map<string, WordType> WordTypeMap = {
        {"a."        , adjective       } ,
        {"adv."      , adverb          } ,
        {"conj."     , conjunction     } ,
        {"n."        , noun            } ,
        {"interj."   , interjections   } ,
        {"imp."      , imperative      } ,
        {"p."        , particple       } ,
        {"prep."     , preposition     } ,
        {"dat."      , dative        }   ,
        {"interrog." , interrogative }   ,

        {"pr."       , pronoun      } ,
        {"pron."     , pronoun      } , /// He   , She  , ...
        {"obj."      , pronoun      } , /// Thou , They , etc


        {"pl."       , plural       } ,
        {"sing."     , singular     } ,
        {"v."        , verb         } ,

        {"object."   , object       } ,
        {"t."        , transitive   } ,
        {"i."        , intransitive } ,
        {"?"        , others        } ,

        /// IGNORE LIST
        {"&"        , IGNORETHIS    } ,
        {"/"        , IGNORETHIS    }
    };

    static map<WordType, string> WordStringMap = {
        {others        , "?."        } ,
        {adjective     , "a."        } ,
        {adverb        , "adv."      } ,
        {conjunction   , "conj."     } ,
        {noun          , "n."        } ,
        {interjections , "interj."   } ,
        {imperative    , "imp."      } ,
        {particple     , "p."        } ,
        {preposition   , "prep."     } ,
        {plural        , "pl."       } ,
        {singular      , "sing."     } ,
        {pronoun       , "pron."     } ,
        {verb          , "v."        } ,
        {object        , "object."   } ,
        {transitive    , "t."        } ,
        {intransitive  , "i."        } ,
        {dative        , "dat."      } ,
        {interrogative , "interrog." } ,

        {IGNORETHIS    , "IGNORE"    }
    };



} /* NLP */
