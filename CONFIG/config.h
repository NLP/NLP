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

//thereexists eWalks(e)^xWalker(e,He)^yWalkTo(e,car)
//From here on is from JOSEPH:
    //GrammarPhrase:
    /**
     * @brief The GrammarPhrase enum Denotes the Grammar Phrase
     */
    enum GrammarPhrase{
        UNKNOWN     = 0,
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
        UNKNOWN,
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
        {    UNKNOWN,       "Unknown"       },
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
        INVALID,
        NONE,
        SUBJECT,
        MAINVERB,
        DIRECTOBJ,
        INDIRECTOBJ,
        MODIFIERVERB
    };

    static const std::map<SyntaxObject,std::string> syntaxLookUp = {
        {   INVALID,        "Invalid"           },
        {   NONE,           "None"              },
        {   SUBJECT,        "Subject"           },
        {   MAINVERB,       "Main Verb"         },
        {   DIRECTOBJ,      "Direct Object"     },
        {   INDIRECTOBJ,    "Indirect Object"   },
        {   MODIFIERVERB,   "Modifier Verb"     }
    };

    static const SyntaxObject soList[] = {
        INVALID,
        NONE,
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

//    enum PoSPhrase{
//        UNKNOWN,
//        NONE,
//        NOUN,
//        VERB,
//        DETERMINER,
//        PREP
//    };

    //Possible coners: PosPhrase -> wordtype and vice-versa
    //since word stores its parts of speech as a wordtype
//    static const std::map<PoSPhrase,std::string> posLookUp = {
//        {UNKNOWN,       "Unknown"       },
//        {NONE,          "None"          },
//        {NOUN,          "Noun"          },
//        {VERB,          "Verb"          },
//        {DETERMINER,    "Determiner"    },
//        {PREP,          "Preposition"   }
//    };

//    static const PoSPhrase posList[] = {
//        UNKNOWN,
//        NONE,
//        NOUN,
//        VERB,
//        DETERMINER,
//        PREP
//    };

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
//Move these:
//    //Structures:
//    struct SyntaxWord{ //Container for a Word and a Syntactical Identifier
//        SyntaxObject _so;
//        Word _word;
//        SyntaxWord(){
//            _so = INVALID; //Does Word have a default constructor?
//        }

//        SyntaxWord(const SyntaxObject& so, const Word& word){
//            _so = so;
//            _word = word;
//        }
//    };
//    bool isHeadWord(const GrammarPhrase& gp, const SyntaxWord& W){
//        switch(gp){
//        case PREPPHRASE:
//        case NOUNPHRASE:{
//            //if W is a noun
//            return true;
//            break;
//        }
//        case SENTENCE:
//        case VERBPHRASE:{
//            //if W is a verb
//            return true;
//            break;
//        }
//        default:{
//            break;
//        }
//        }
//        return false;
//    }

//    bool isPoS(const GrammarPhrase& gp){
//        for(auto& i : posList){
//            if(i == gp)
//                return true;
//        }
//        return false;
//    }

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

} /* NLP */
