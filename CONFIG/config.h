#pragma once

#include <map>
#include <QtSql>

using namespace std;

namespace NLP
{

    // word tag? there are more, see .dat for list of them
    enum WordType {
        others = 0,
        adjective , adverb        , conjunction , dative,
        noun      , interjections , imperative  ,
        particple , preposition   , pronoun     , plural , singular,
        verb      , transitive, intransitive, interrogative, object,
        determiner,

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

        {"det."      , determiner   } ,

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
        {determiner    , "det."      } ,

        {IGNORETHIS    , "IGNORE"    }
    };

//thereexists eWalks(e)^xWalker(e,He)^yWalkTo(e,car)
//From here on is from JOSEPH:
    //GrammarPhrase:
    /**
     * @brief The GrammarPhrase enum Denotes the Grammar Phrase
     */
    enum GrammarPhrase{
        G_INVALID   = 0,
        ALL         = 1,
        SENTENCE    = 2,
        NOUNPHRASE  = 3,
        VERBPHRASE  = 4,
        PREPPHRASE  = 5,
        NOMINAL     = 6,
        NOUN        = 7,
        VERB        = 8,
        PREP        = 9,
        DETERMINER  = 10
    };
    /**
      * @brief gpList The array that holds all of the Grammar Phrase enumerations.
      */
    static const GrammarPhrase gpList[] ={
        G_INVALID,
        ALL,
        SENTENCE,
        NOUNPHRASE,
        VERBPHRASE,
        PREPPHRASE,
        NOMINAL,
        NOUN,
        VERB,
        PREP,
        DETERMINER
    };

    /**
      * @brief phraseLookUp The map that converst the GrammarPhrase enumeration to a string
      */
    static std::map<GrammarPhrase,std::string> phraseLookUp = {
        {    G_INVALID,     "Invalid"       },
        {    ALL,           "All"           },
        {    SENTENCE,      "Sentence"      },
        {    NOUNPHRASE,    "Noun Phrase"   },
        {    VERBPHRASE,    "Verb Phrase"   },
        {    PREPPHRASE,    "Prep. Phrase"  },
        {    NOMINAL,       "Nominal"       },
        {    NOUN,          "Noun"          },
        {    VERB,          "Verb"          },
        {    PREP,          "Preposition"   },
        {    DETERMINER,    "Determiner"    }

    };

    enum SyntaxObject{
        S_INVALID,
        S_NONE,
        SUBJECT,
        MAINVERB,
        DIRECTOBJ,
        INDIRECTOBJ,
        MODIFIERVERB
    };

    static std::map<SyntaxObject,std::string> syntaxLookUp = {
        {   S_INVALID,      "Invalid"           },
        {   S_NONE,         "None"              },
        {   SUBJECT,        "Subject"           },
        {   MAINVERB,       "Main Verb"         },
        {   DIRECTOBJ,      "Direct Object"     },
        {   INDIRECTOBJ,    "Indirect Object"   },
        {   MODIFIERVERB,   "Modifier Verb"     }
    };

    static const SyntaxObject soList[] = {
        S_INVALID,
        S_NONE,
        SUBJECT,
        MAINVERB,
        DIRECTOBJ,
        INDIRECTOBJ,
        MODIFIERVERB
    };

    static const GrammarPhrase posList[] = {
        NOUN,
        VERB,
        DETERMINER,
        PREP
    };

    enum SentenceType{
        DECLARATIVE,
        IMPERATIVE,
        INTERROGATIVE
//        QUESTION
    };

    //Typedefs:
    /**
     * @brief GPlist typedef for vector<GrammarPhrase>
     */
    typedef std::vector<GrammarPhrase> GPlist;
    /**
     * @brief mmap typedef for multimpa<GrammarPhrase, vector<GrammarPhrase> >
     */
    typedef std::multimap<GrammarPhrase,GPlist> mmap;
    /**
     * @brief GPpair typedef for pair<GrammarPhrase, vector<GrammarPhrase> >
     */
    typedef std::pair<GrammarPhrase,GPlist> GPpair;




    //Initializer List for Reduced Context Free Grammar of Order Zero
    /**
      * @brief cfgzInit an array of GPpairs that hold the definition for the Context Free Grammmar of Order Zero
      */
    static const GPpair cfgzInit[] = {
        GPpair(SENTENCE,{NOUNPHRASE,VERBPHRASE}),
        GPpair(NOUNPHRASE,{NOUN}),
        GPpair(NOUNPHRASE,{DETERMINER,NOUN}),
        GPpair(VERBPHRASE,{VERB}),
        GPpair(VERBPHRASE,{VERB,NOUNPHRASE}),
        GPpair(VERBPHRASE,{VERB,NOUNPHRASE,PREPPHRASE}),
        GPpair(VERBPHRASE,{VERB,PREPPHRASE}),
        GPpair(PREPPHRASE,{PREP,NOUNPHRASE})
    };
//    others = 0,
//    adjective , adverb        , conjunction , dative,
//    , interjections , imperative  ,
//    particple , preposition   , pronoun     , plural , singular,
//    , transitive, intransitive, interrogative, object,

//    IGNORETHIS

    static std::map<WordType,GrammarPhrase> WTtoGP = {
        {noun,NOUN},
        {verb,VERB},
        {preposition,PREP},
        {determiner,DETERMINER}
    };

    static GrammarPhrase nonobjects[] = {
        DETERMINER,
    };

} /* NLP */
