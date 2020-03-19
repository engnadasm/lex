#ifndef NDCONVERTER_H
#define NDCONVERTER_H


class NDConverter
{
    public:
        NDConverter(NFA nfa);
        void convert();
        DFA getDFA();

    protected:

    private:
};

#endif // NDCONVERTER_H
