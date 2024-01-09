#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <functional>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

namespace shakespeare
{
    /** type alias for a pair of tokens */
    using TokenPair = std::pair<std::string, std::string>;

    /** overload hash function for std::pair */
    struct pairhash {
    	template <typename T1, typename T2>
        std::size_t operator()(const std::pair<T1, T2>& pair) const
	{
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    /** Defines a tokenizer that implements the SentencePiece method */
    class Tokenizer
    {
    public:
	/** constructor */
        Tokenizer();

	/** destructor */
	~Tokenizer();

	/** Creates a vocabulary of tokens using SentencePiece method
	@param corpus Sentences used to train the tokenizer
	@param vocab_size Desired vocabulary/token size
	*/
        void Train(const std::vector<std::string>& corpus, size_t vocab_size);

	/** Uses training to convert a sentence into a vector of tokens
	@param input Sentence to tokenize
	*/
	std::vector<std::string> Tokenize(const std::string& input);

	/** Saves the vocabulary that was produced from training tokenizer
	@param filename Name of the file to save vocabulary to
	*/
	void SaveModel(const std::string& filename);

	/** Loads vocabulary from a file
	@param filename Name of the file to load vocabulary from
	*/
	void LoadModel(const std::string& filename);
    private:
	/** The vocabulary of tokens, each assigned their frequencies */
        std::unordered_map<std::string, size_t> vocab_;

	/** Generates single-character tokens from corpus
	@param corpus Sentences, typically used for training purposes
	*/
	void InitVocab(const std::vector<std::string>& corpus);

	/** Produces most frequent pair of tokens that appear in corpus
	@param corpus Sentences, typically used for training purposes
	*/
	std::pair<TokenPair, size_t> FindMostFrequentTokenPair(
	    const std::vector<std::string>& corpus);

	/** Loads new token into the vocabulary
	@param new_token New token that was found or created
	*/
	void UpdateVocab(const TokenPair& pair, size_t frequency);
    }; // class Tokenizer
} // namespace shakespeare

#endif
