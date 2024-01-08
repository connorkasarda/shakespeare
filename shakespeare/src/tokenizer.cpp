#include <algorithm>
#include <functional>
#include "tokenizer.h"

namespace shakespeare
{
    Tokenizer::Tokenizer() = default;
    // -------------------------------------------------------------------------
    Tokenizer::~Tokenizer()
    {
    }
    // -------------------------------------------------------------------------
    void Tokenizer::Train(const std::vector<Sentence>& corpus,
			  size_t vocab_size)
    {
        InitVocab(corpus);
	// TODO: loop until the vocab size is desirable
        /*
	while (vocab_.size() < vocab_size)
	{
	*/
	    std::pair<Token, Token> most_freq_pair =
		FindMostFrequentPair(corpus);
	    // TODO: merge most frequent pair into token
	    // TODO: update the vocabulary
	    // TODO: replace most frequent pair with new token in corpus
	/*
	}
	*/
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
    // std::pair is not hashable on its own so an implementation was needed
    // for the FindMostFrequentPair function. May look into better organization
    // for adding this implementation later.
    struct pair_hash
    {
        template <class T1, class T2>
        std::size_t operator () (const std::pair<T1, T2>& p) const
        {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;
        }
    };
    // -------------------------------------------------------------------------
    std::pair<Token, Token> Tokenizer::FindMostFrequentPair(
	const std::vector<Sentence>& corpus)
    {
	std::unordered_map<std::pair<Token, Token>, Frequency, pair_hash>
	    pair_frequencies;
	for (const Sentence& sentence : corpus)
	{
	    size_t sentence_len = sentence.size();
	    for (size_t i = 0; i < sentence_len - 1; ++i)
	    {
		std::pair<Token, Token> pair =
		{
		    Token(1, sentence[i]),
		    Token(1, sentence[i + 1])
		};
		pair_frequencies[pair]++;
	    }
	}
	auto most_freq_pair = std::max_element(
	    pair_frequencies.begin(),
	    pair_frequencies.end(),
 	    [](const auto& lhs, const auto& rhs)
	    {
	        return lhs.second < rhs.second;
	    });
	return most_freq_pair->first;
    }
    // -------------------------------------------------------------------------
    void UpdateVocab(const Token& new_token)
    {
    }
    // -------------------------------------------------------------------------
    void ReplaceMostFrequentPair(std::vector<Sentence>& corpus,
        			 const std::pair<Token, Token>& pair,
        			 const Token& new_token)
    {
    }
} // namespace shakespeare
