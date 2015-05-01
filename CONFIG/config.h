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
        determiner, question,

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
        {"interrog." , interrogative }   , //Need to change the Wh words into interoggs

        {"pr."       , pronoun      } ,
        {"pron."     , pronoun      } , /// He   , She  , ...
        {"obj."      , pronoun      } , /// Thou , They , etc


        {"pl."       , plural       } ,
        {"sing."     , singular     } ,
        {"v."        , verb         } ,

        {"object."   , pronoun       } , //previously mapped to object
        {"t."        , transitive   } ,
        {"i."        , intransitive } ,

        {"det."      , determiner   } ,
        {"q."        , question     } ,

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
        {question      , "q."        } ,

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
        DETERMINER  = 10,

        INTPHRASE,
        WHPHRASE,
        WHWORD,
        AUXILARY
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
        DETERMINER,
        INTPHRASE,
        WHPHRASE,
        WHWORD,
        AUXILARY
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
        {    DETERMINER,    "Determiner"    },
        {    INTPHRASE ,    "Inter. Phrase" },
        {    WHPHRASE,      "Wh. Phrase"    },
        {    WHWORD,        "Wh. Word"      },
        {    AUXILARY,      "Auxilary"      }

    };

    enum SyntaxObject{
        S_INVALID,
        S_NONE,
        SUBJECT,
        MAINVERB,
        DIRECTOBJ,          /// He eats "apple"
        INDIRECTOBJ,       /// He kicks the ball to "him"
        AUX,
        QWORD
    };

    static std::map<SyntaxObject,std::string> syntaxLookUp = {
        {   S_INVALID,      "Invalid"           },
        {   S_NONE,         "None"              },
        {   SUBJECT,        "Subject"           },
        {   MAINVERB,       "Main Verb"         },
        {   DIRECTOBJ,      "Direct Object"     },
        {   INDIRECTOBJ,    "Indirect Object"   },
        {   AUX,            "Auxilary Verb"     },
        {   QWORD,          "Question Word"     }
    };

    static const SyntaxObject soList[] = {
        S_INVALID,
        S_NONE,
        SUBJECT,
        MAINVERB,
        DIRECTOBJ,
        INDIRECTOBJ,
        AUX,
        QWORD
    };

    static const GrammarPhrase posList[] = {
        NOUN,
        VERB,
        DETERMINER,
        PREP,
        WHWORD
    };

    enum SentenceType{
        ST_INVALID,
        DECLARATIVE,
        IMPERATIVE,
        INTERROGATIVE
//        QUESTION
    };

    static const SentenceType sentenceList[] = {
         ST_INVALID,
        DECLARATIVE,
        IMPERATIVE,
        INTERROGATIVE
    };

    static  std::map<SentenceType,std::string> sentenceLookUp = {
        {ST_INVALID,    "Invalid"    },
        {DECLARATIVE,   "Declarative"},
        {IMPERATIVE,    "Imperative" },
        {INTERROGATIVE, "Interrogative"}
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

    static const GPpair cfgqInit[] = {
        GPpair(SENTENCE,{INTPHRASE,NOUNPHRASE,VERBPHRASE}),
        GPpair(SENTENCE,{INTPHRASE,VERBPHRASE}),
        GPpair(SENTENCE,{INTPHRASE,NOUNPHRASE}),
        GPpair(SENTENCE,{NOUNPHRASE,VERBPHRASE}),
        GPpair(NOUNPHRASE,{DETERMINER,NOUN}),
        GPpair(NOUNPHRASE,{NOUN}),
        GPpair(VERBPHRASE,{VERB,NOUNPHRASE,PREPPHRASE}),
        GPpair(VERBPHRASE,{VERB,NOUNPHRASE}),
        GPpair(VERBPHRASE,{VERB,PREPPHRASE}),
        GPpair(VERBPHRASE,{VERB}),
        GPpair(PREPPHRASE,{PREP,NOUNPHRASE}),
        GPpair(PREPPHRASE,{PREP}),
        GPpair(INTPHRASE,{WHPHRASE,AUXILARY}),
        GPpair(INTPHRASE,{AUXILARY}),
        GPpair(INTPHRASE,{WHPHRASE}),
        GPpair(WHPHRASE,{WHWORD}),
        GPpair(AUXILARY,{VERB})
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
        {determiner,DETERMINER},
        {pronoun,NOUN},
        {question,WHWORD}
    };

    static std::map<GrammarPhrase,WordType> GPtoWT = {
        {NOUN,noun},
        {VERB,verb},
        {PREP,preposition},
        {DETERMINER,determiner},
        {WHWORD,question}
//        {pronoun,NOUN}
    };



} /* NLP */
