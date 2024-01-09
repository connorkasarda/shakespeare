#include <algorithm>
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
	const std::vector<std::string>& corpus,
	size_t vocab_size)
    {
        InitVocab(corpus);
	// TODO WHILE THE SIZE OF THE VOCAB IS LESS THAN DESIRABLE SIZE
	    // TODO 1. FIND MOST FREQUENTLY OCCURING TOKEN PAIR
	    // TODO 2. CREATE NEW TOKEN FROM MOST FREQUENT TOKEN PAIR
	    // TODO 3. UPDATE VOCAB WITH NEW MERGED TOKEN AND FREQUENCY
    }
    // -------------------------------------------------------------------------
    std::vector<std::string> Tokenizer::Tokenize(const std::string& input)
    {
        return std::vector<std::string>();
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
    void Tokenizer::InitVocab(const std::vector<std::string>& corpus)
    {
        for (const std::string& sentence : corpus)
        {
	    for (char c : sentence)
	    {
		std::string token(1, c);
		vocab_[token]++;
	    }
        }
    }
    // -------------------------------------------------------------------------
    std::pair<TokenPair, size_t> Tokenizer::FindMostFrequentTokenPair(
	const std::vector<std::string>& corpus)
    {
	std::unordered_map<TokenPair, size_t, pairhash> token_pairs_freqs;
	// TODO NEED TO TOKENIZE EACH SENTENCE FIRST.
	//      THIS WOULD REQUIRE USE OF THE TOKENIZE METHOD.
        //      ITERATE OVER EACH PAIR OF TOKENS,
	//	UPDATING TOKEN PAIRS FREQS VALUE AS YOU GO.
	auto most_freq_pair = std::max_element(
	    token_pairs_freqs.begin(),
	    token_pairs_freqs.end(),
 	    [](const auto& lhs, const auto& rhs)
	    {
	        return lhs.second < rhs.second;
	    });
	return {most_freq_pair->first, most_freq_pair->second};
    }
    // -------------------------------------------------------------------------
    void Tokenizer::UpdateVocab(const TokenPair& pair, size_t frequency)
    {
	vocab_[pair.first + pair.second] = frequency;
	vocab_[pair.first] -= frequency;
	vocab_[pair.second] -= frequency;
    }
} // namespace shakespeare
