/*
Interface for normalizer types.
*/

#ifndef NORMALIZER_H
#define NORMALIZER_H

namespace shakespeare
{
    /** interface for normalizer types */
    class Normalizer
    {
    public:
        /** constructor */
        Normalizer() {}
        /** destructor */
        virtual ~Normalizer() {}
    }; // class Normalizer
} // namespace shakespeare

#endif // NORMALIZER_H
