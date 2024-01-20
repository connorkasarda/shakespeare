/*
Interface for tokenization models.
*/

#ifndef MODEL_H
#define MODEL_H

namespace shakespeare
{
    /** interface for model types */
    class Model
    {
    public:
        /** constructor  */
        Model() {}
        /** destructor */
        virtual ~Model() {}
    }; // class Model
} // namespace shakespeare

#endif // MODEL_H
