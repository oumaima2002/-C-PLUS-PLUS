#ifndef FORME_H
#define FORME_H
class Forme
{

private:
    // pas de parametre
public:
    virtual void Afficher() = 0;
    virtual double Surface() const = 0;
};
#endif