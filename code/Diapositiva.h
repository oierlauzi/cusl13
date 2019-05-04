#pragma once

#include <list>
#include <memory>

class Diapositiva{
public:
    virtual void onIn()=0;
    virtual void onOut()=0;
};

#define DIAP_BEGIN(name) class name : public Diapositiva {
#define DIAP_END(name) \
}; \
    diapos.push_back(std::unique_ptr<Diapositiva>(new name));

#define DIAP_PRIV_OBJ_BEGIN private: 
#define DIAP_PRIV_OBJ_END

#define DIAP_ONIN_BEGIN virtual void onIn() override{
#define DIAP_ONIN_END }

#define DIAP_ONOUT_BEGIN virtual void onOut() override{
#define DIAP_ONOUT_END }

#define PRESENTACION_BEGIN(name) \
    inline std::list<std::unique_ptr<Diapositiva>> get_pres_##name(){ \
        std::list<std::unique_ptr<Diapositiva>> diapos;

#define PRESENTACION_END(name) \
        return diapos; \
    }
#define GET_PRESENTACION(name) get_pres_##name()