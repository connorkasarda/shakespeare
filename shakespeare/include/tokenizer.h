#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

namespace shakespeare
{
    /** A sentence, typically derived from a corpus dataset */
    using Sentence = std::string;

    /** A token, typically derived from a sentence */
    using Token = std::string;

    /** The number of occurances of a token */
    using Frequency = int;

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
        void Train(const std::vector<Sentence>& corpus, size_t vocab_size);

	/** Uses training to convert a sentence into a vector of tokens
	@param input Sentence to tokenize
	*/
	std::vector<Token> Tokenize(const Sentence& input);

	/** Saves the vocabulary that was produced from training tokenizer
	@param filename Name of the file to save vocabulary to
	*/
	void SaveModel(const std::string& filename);

	/** Loads vocabulary from a file
	@param filename Name of the file to load vocabulary from
	*/
	void LoadModel(const std::string& filename);
    private:
	/** The vocabulary of tokens */
        std::unordered_map<Token, int> vocab_;

	/** Generates single-character tokens from corpus
	@param corpus Sentences, typically used for training purposes
	*/
	void InitVocab(const std::vector<Sentence>& corpus);

	/** Produces most frequent pair of tokens that appear in corpus
	@param corpus Sentences, typically used for training purposes
	*/
	std::pair<Token, Token> FindMostFrequentPair(
	    const std::vector<Sentence>& corpus);

	/** Loads new token into the vocabulary
	@param new_token New token that was found or created
	*/
	void UpdateVocab(const Token& new_token);

	/** Replaces most frequent pair with a merged token
	@param corpus Sentences used for training purposes
	@param pair Pair of tokens to replace
	@param new_token Merged version of token pair
	*/
	void ReplaceMostFrequentPair(std::vector<Sentence>& corpus,
            const std::pair<Token, Token>& pair,
            const Token& new_token);
    }; // class Tokenizer
} // namespace shakespeare

#endif
