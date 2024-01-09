#include <algorithm>
#include <functional>
#include "tokenizer.h"

namespace shakespeare
{
    Tokenizer::Tokenizer()
    {
    }
    // -------------------------------------------------------------------------
    Tokenizer::~Tokenizer()
    {
    }
    // -------------------------------------------------------------------------
    void Tokenizer::Train(
	const std::vector<Sentence>& corpus,
	size_t vocab_size)
    {
        InitVocab(corpus);
	/* while (vocab_.size() < vocab_size)
	{
	    // TODO: 1. FIND MOST FREQUENTLY OCCURING MERGED TOKEN
	    // TODO: 2. CREATE NEW TOKEN STRING FROM MERGED TOKEN
	    // TODO: 3. UPDATE VOCAB WITH NEW TOKEN AND FREQUENCY
	} */
    }
    // -------------------------------------------------------------------------
    std::vector<Token> Tokenizer::Tokenize(const Sentence& input)
    {
        return std::vector<Token>();
    }
    // -------------------------------------------------------------------------
    void Tokenizer::SaveModel(const std::string& filename)
    {
    }
    // -------------------------------------------------------------------------
    void Tokenizer::LoadModel(const std::string& filename)
    {
    }
    // -------------------------------------------------------------------------
    void Tokenizer::InitVocab(const std::vector<Sentence>& corpus)
    {
        for (const Sentence& sentence : corpus)
        {
	    for (char c : sentence)
	    {
		Token token(1, c);
		vocab_[token]++;
	    }
        }
    }
    // -------------------------------------------------------------------------
    // TODO: CREATE A FUNCTION THAT SIMPLY FINDS THE FREQUENCIES OF PAIRS IN THE
    //       CORPUS AFTER IT HAS BEEN TEMPORARILY TOKENIZED. THIS WOULD THEN BE
    // 	     USED BY THE FIND MOST FREQUENT PAIR FUNCTION
    std::unordered_map<Token, Frequency> FindMergedTokenFrequencies(
	const std::vector<Sentence>& corpus)
    {
	return {};
    }
    // -------------------------------------------------------------------------
    std::pair<Token, Frequency> Tokenizer::FindMostFrequentMergedToken(
	const std::vector<Sentence>& corpus)
    {
	std::unordered_map<Token, Frequency> merged_token_freqs;
	// TODO: NEED TO TOKENIZE EACH SENTENCE FIRST, MAY CHANGE THE
	//       IMPLEMENTATION BELOW. THIS WOULD REQUIRE USE OF THE
	//       TOKENIZE METHOD IN THIS TOKENIZER CLASS. ITERATE OVER
	// 	 EACH PAIR OF MERGED TOKENS, UPDATING MERGED_TOKEN_FREQS
	//	 AS YOU GO. THIS WILL BE DONE BY FIND MERGED TOKEN FREQUENCIES
	//       FUNCTION THAT CAN BE FOUND ABOVE THIS FUNCTION.
	auto most_freq_token_and_freq = std::max_element(
	    merged_token_freqs.begin(),
	    merged_token_freqs.end(),
 	    [](const auto& lhs, const auto& rhs)
	    {
	        return lhs.second < rhs.second;
	    });
	return std::make_pair(Token(), Frequency()); // most_freq_token_and_freq
    }
    // -------------------------------------------------------------------------
    // TODO: REQUIRES A REWORK SINCE WHEN A NEW TOKEN IS ADDED, IT ISN'T SIMPLY
    //       INCREASING ITS OCCURANCE BY 1. NEED TO MAKE SURE NEW TOKEN'S
    // 	     OCCURANCE IS ADDED AND THAT PREVIOUS OCCURANCE OF TOKENS MERGED
    //	     INTO NEW TOKEN SHOULD BE REMOVED
    void Tokenizer::UpdateVocab(const Token& new_token, Frequency new_token_freq)
    {
	// vocab_[new_token_from_a_&_b] = ~~ actual discovered frequency ~~
	// vocab_[token_a] -= ~~ actual discovered frequency of new_token ~~
	// vocab_[token_b] -= ~~ actual discovered frequency of new_token ~~
    }
} // namespace shakespeare
