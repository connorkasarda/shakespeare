#include "tokenizer.h"

namespace shakespeare
{
    Tokenizer::Tokenizer() = default;
    void Tokenizer::Train
    (
        const std::vector<Sentence>& corpus,
        size_t vocab_size
    )
    {
        
    }
    std::vector<Token> Tokenizer::Tokenize(const Sentence& input)
    {
        return std::vector<Token>();
    }
    void Tokenizer::SaveModel(const std::string& filename)
    {
        
    }
    void Tokenizer::LoadModel(const std::string& filename)
    {
        
    }
    void Tokenizer::InitVocab(const std::vector<Sentence>& corpus)
    {
        
    }
    std::pair<Token, Token> FindMostFrequentPair
    (
        const std::vector<Sentence>& corpus
    )
    {
        return std::make_pair(Token(), Token());
    }
    void UpdateVocab(const Token& new_token)
    {
        
    }
    void ReplaceMostFrequentPair
    (
        std::vector<Sentence>& corpus,
        const std::pair<Token, Token>& pair,
        const Token& new_token
    )
    {
        
    }
}
