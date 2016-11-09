#ifndef SISTEMA_H_
#define SISTEMA_H_ 

#include <cassert>

void imprimir_bus_mas(int max1, int max2, int max3){
    if ((max1>=max2)&&(max1>=max3)){
        std::cout <<"El bus mas utilizado es Semi-cama y es utilizado "<< max1 <<std::endl;
    }
    else if((max2>=max1)&&(max2>=max3)){
        std::cout<<"El bus mas utilizado es Salon-cama y es utilizado " << max2<<std::endl;
    }
    else if((max3>=max1)&&(max3>=max2)){
        std::cout<<"El bus mas utilizado es Premium y es utilizado " << max3<<std::endl;
    }
}

std::string origen_destino(int indice){
    if(indice==0){
        return "Santiago";
    }
    else if(indice==1){
        return "Rancagua";
    }
    else if(indice==2){
        return "Valparaiso";
    }
    else if(indice==3){
        return "La Serena";
    }
    else{
        return "deja de jakear el codigo xd xd +10 pa pu";
    }
}

std::string viajes(int max){
    if(max==0){
        return "Santiago - Rancagua";
    }
    else if(max==1){
        return "Santiago - Valparaiso";
    }
    else if(max==2){
        return "Santiago - La Serena";
    }
    else if(max==3){
        return "Rancagua - Santiago";
    }
    else if(max==4){
        return "Rancagua - Valparaiso";
    }
    else if(max==5){
        return "Rancagua - La Serena";
    }
    else if(max==6){
        return "Valparaiso - Santiago";
    }
    else if(max==7){
        return "Valparaiso - Rancagua";
    }
    else if(max==8){
        return "Valparaiso - La Serena";
    }
    else if(max==9){
        return "La Serena - Santiago";
    }
    else if(max==10){
        return "La Serena - Rancagua";
    }        
    else if(max==11){
        return "La Serena - Valparaiso";
    }
    else{
        return " no se encontro el destino, porfavor verificar el codigo :)";
    }
}

class Bus {
protected:
    std::vector<std::string> asientos_;
    std::string tipo_;
    std::string origen_;
    std::string destino_;
    int precio_;
    int hora_;
   
public:
    Bus(std::string tipo, size_t asientos, std::string origen, std::string destino, int precio, int hora) {
        assert(origen!=destino);
        assert(origen=="Santiago" || origen == "Rancagua" || origen== "Valparaiso" || origen=="La Serena");
        assert(destino=="Santiago" || destino == "Rancagua" || destino == "Valparaiso" || destino =="La Serena");    
        assert(tipo == "Semi-Cama" || tipo == "Salon-Cama" || tipo == "Premium    " );
        assert( 0<=hora && hora<24);
        if(tipo=="Semi-Cama"){
        asientos=45;
        }
        else if(tipo=="Salon-Cama"){
        asientos=30;
        }
        else{
            asientos=20;
        }

        for (size_t i = 0; i < asientos; i++)
        {
            asientos_.push_back("");
        }
        tipo_ = tipo;
        origen_ = origen;
        destino_ = destino;
        precio_ = precio;
        hora_ = hora;
    }

    virtual void listarAsientos() {
        std::cout << "Asientos disponibles del bus : ";
        for (size_t i = 0; i < asientos_.size(); i++)
        {  
            if(asientos_[i].size() == 0) 
            {
                std::cout << i+1 << " ";
            }
        }
        std::cout << std::endl;

        std::cout << "Asientos vendidos del bus: ";
        for (size_t i = 0; i < asientos_.size(); i++)
        {
            if(asientos_[i].size() != 0)
            {
                std::cout << i+1 << ": " << asientos_[i] << std::endl;
            }
        }
        std::cout << std::endl;
    }

    bool venderAsiento(int asiento, std::string rut) {
        if(asientos_[asiento-1].size() == 0) {
            asientos_[asiento-1] = rut;
            return true;
        }
        return false;
    }

    virtual void info() {
        std::cout << origen_ << "\t" << destino_ << "\t" << tipo_ << "\t" << hora_;
    }

    virtual std::string gettipo_(){
        return tipo_;
    }

    virtual std::string getorigen_(){
        return origen_;
    }

    virtual std::string getdestino_(){
        return destino_;
    }

    virtual int getprecio_(){
        return precio_;
    }

    virtual int gethora_(){
        return hora_;
    }

    virtual void settipo_(std::string tipo){
        tipo_ = tipo;
    }
    
    virtual void setorigen_(std::string origen){
        origen_=origen;
    }
    
    virtual void setdestino_(std::string destino){
        destino_=destino;
    }
    
    virtual void setprecio_(int precio){
        precio_=precio;
    }

    virtual void sethora_(int hora){
        hora_=hora;
    }

};



class Bus_semicama: public Bus{
public:
    Bus_semicama(std::string tipo, size_t asientos, std::string origen, std::string destino, int precio, int hora) : Bus(tipo, asientos, origen, destino, precio, hora){
        assert(tipo=="Semi-Cama");

        if(origen_=="Santiago"){
            if(destino_=="Rancagua"){
                precio_=4000;
            }
            else if(destino_=="Valparaiso"){
                precio_=2000;
            }
            else {
                precio_=7000;
            }

        }
        else if(origen_=="Rancagua"){
            if(destino_=="Santiago"){
                precio_=4000;
            }
            else if(destino_=="Valparaiso"){
                precio_=6000;
            }
            else{
                precio_=9000;
            }
        }
        else if(origen_=="Valparaiso"){
            if(destino_=="Santiago"){
                precio_=2000;
            }
            else if(destino_=="Rancagua"){
                precio_=6000;
            }
            else{
                precio_=5000;
            }   
        }
        else{
            if(destino_=="Santiago"){
                precio_=7000;
            }
            else if(destino_=="Rancagua"){
                precio_=9000;
            }
            else{
                precio_=5000;
            }
        }    
    
    }

     std::string gettipo_(){
        return "Semi-Cama";
    }

    void info() {
        std::cout <<"El bus que va desde "<< origen_ << " hasta " << destino_ << " del tipo " << gettipo_() << " que sale a las " << hora_ << std::endl;
    }

    void listarAsientos() {
        std::cout << "Asientos disponibles del bus Semi-Cama: ";
        for (int i = 0; i < 45; i++)
        {  
            if(asientos_[i].size() == 0) 
            {
                std::cout << i+1 << " ";
            }
        }
        std::cout << std::endl;

        std::cout << "Asientos vendidos del bus Semi-Cama: ";
        for (int i = 0; i < 45; i++)
        {
            if(asientos_[i].size() != 0)
            {
                std::cout << i+1 << ": " << asientos_[i] << std::endl;
            }
        }
        std::cout << std::endl;
    }

};

class Bus_saloncama: public Bus{
public:
    Bus_saloncama(std::string tipo, size_t asientos, std::string origen, std::string destino, int precio, int hora):Bus(tipo, asientos, origen, destino, precio, hora){ 
    assert(tipo=="Salon-Cama");  


        if(origen_=="Santiago"){
            if(destino_=="Rancagua"){
                precio_=8000;
            }
            else if(destino_=="Valparaiso"){
                precio_=4000;
            }
            else {
                precio_=10000;
            }

        }
        else if(origen_=="Rancagua"){
            if(destino_=="Santiago"){
                precio_=8000;
            }
            else if(destino_=="Valparaiso"){
                precio_=8000;
            }
            else{
                precio_=14000;
            }
        }
        else if(origen_=="Valparaiso"){
            if(destino_=="Santiago"){
                precio_=4000;
            }
            else if(destino_=="Rancagua"){
                precio_=8000;
            }
            else{
                precio_=8000;
            }   
        }
        else{
            if(destino_=="Santiago"){
                precio_=10000;
            }
            else if(destino_=="Rancagua"){
                precio_=14000;
            }
            else{
                precio_=8000;
            }
        }
    }

    std::string gettipo_(){
        return "Salon-Cama";
    }

    void info() {
        std::cout <<"El bus que va desde "<< origen_ << " hasta " << destino_ << " del tipo " << gettipo_() << " que sale a las " << hora_ << std::endl;
    }

    void listarAsientos() {
        std::cout << "Asientos disponibles del bus salon-cama: ";
        for (int i = 0; i < 30; i++)
        {  
            if(asientos_[i].size() == 0) 
            {
                std::cout << i+1 << " ";
            }
        }
        std::cout << std::endl;

        std::cout << "Asientos vendidos del bus salon-cama: ";
        for (int i = 0; i < 30; i++)
        {
            if(asientos_[i].size() != 0)
            {
                std::cout << i+1 << ": " << asientos_[i] << std::endl;
            }
        }
        std::cout << std::endl;
    }

};

class Bus_premium: public Bus{
public:
    Bus_premium(std::string tipo, size_t asientos, std::string origen, std::string destino, int precio, int hora) : Bus(tipo, asientos, origen, destino, precio, hora){
        assert(tipo=="Premium    ");

        if(origen_=="Santiago"){
            if(destino_=="Rancagua"){
                precio_=12000;
            }
            else if(destino_=="Valparaiso"){
                precio_=6000;
            }
            else {
                precio_=13000;
            }

        }
        else if(origen_=="Rancagua"){
            if(destino_=="Santiago"){
                precio_=12000;
            }
            else if(destino_=="Valparaiso"){
                precio_=10000;
            }
            else{
                precio_=19000;
            }
        }
        else if(origen_=="Valparaiso"){
            if(destino_=="Santiago"){
                precio_=6000;
            }
            else if(destino_=="Rancagua"){
                precio_=10000;
            }
            else{
                precio_=11000;
            }   
        }
        else{
            if(destino_=="Santiago"){
                precio_=13000;
            }
            else if(destino_=="Rancagua"){
                precio_=19000;
            }
            else{
                precio_=11000;
            }
        }
    }

    std::string gettipo_(){
        return "Premium";
    }

    void info() {
        std::cout <<"El bus que va desde "<< origen_ << " hasta " << destino_ << " del tipo " << gettipo_() << " que sale a las " << hora_ << std::endl;
    }

    void listarAsientos() {
        std::cout << "Asientos disponibles del bus premium: ";
        for (int i = 0; i < 20; i++)
        {  
            if(asientos_[i].size() == 0) 
            {
                std::cout << i+1 << " ";
            }
        }
        std::cout << std::endl;

        std::cout << "Asientos vendidos del bus premium: ";
        for (int i = 0; i < 20; i++)
        {
            if(asientos_[i].size() != 0)
            {
                std::cout << i+1 << ": " << asientos_[i] << std::endl;
            }
        }
        std::cout << std::endl;
    }

};

void recorridos(std::vector<Bus> &tipo, std::vector<int> &N_viajes){

     for(size_t i=0;i<tipo.size();i++){
        if(tipo[i].getorigen_()=="Santiago"){
            if(tipo[i].getdestino_()=="Rancagua"){
                N_viajes[0]++;
            }
            else if(tipo[i].getdestino_()=="Valparaiso"){
                N_viajes[1]++;
            }
            else {
                N_viajes[2]++;
            }
        }
        else if(tipo[i].getorigen_()=="Rancagua"){
            if(tipo[i].getdestino_()=="Santiago"){
                N_viajes[3]++;
            }
            else if(tipo[i].getdestino_()=="Valparaiso"){
                N_viajes[4]++;
            }
            else{
                N_viajes[5]++;
            }
        }
        else if(tipo[i].getorigen_()=="Valparaiso"){
            if(tipo[i].getdestino_()=="Santiago"){
                N_viajes[6]++;
            }
            else if(tipo[i].getdestino_()=="Rancagua"){
                N_viajes[7]++;
            }
            else{
                N_viajes[8]++;
            }   
        }
        else{
            if(tipo[i].getdestino_()=="Santiago"){
                N_viajes[9]++;
            }
            else if(tipo[i].getdestino_()=="Rancagua"){
                N_viajes[10]++;
            }
            else{
                N_viajes[11]++;
            }
        }
    }
}

void origen_del_recorrido(std::vector<Bus> &tipo, std::vector<int> &N_tipo){
    for (size_t i=0;i<tipo.size();i++){
        if(tipo[i].getdestino_()=="Santiago"){
            N_tipo[0]++;
            }
        else if(tipo[i].getdestino_()=="Rancagua"){
            N_tipo[1]++;
            }
        else if(tipo[i].getdestino_()=="Valparaiso"){
            N_tipo[2]++;
            }
        else{
            N_tipo[3]++;
            }
        }
}

void final_del_recorrido(std::vector<Bus> &tipo, std::vector<int> &N_tipo){
     for (size_t i=0;i<tipo.size();i++){
            if(tipo[i].getdestino_()=="Santiago"){
                N_tipo[0]++;
            }
            else if(tipo[i].getdestino_()=="Rancagua"){
                N_tipo[1]++;
            }
            else if(tipo[i].getdestino_()=="Valparaiso"){
                N_tipo[2]++;
            }
            else{
                N_tipo[3]++;
            }
        }
}

void mostrarBus(int bus, std::vector<Bus*> &tipo) {
        tipo[bus]->listarAsientos();
}


class Persona{
    int plata_;
    std::string rut_;
public:
    Persona(int plata, std::string rut){
        plata_=plata;
        rut_=rut;
    }

    std::string getrut_(){
        return rut_;
    }

    int getplata_(){
        return plata_;
    }

    void setplata_(int plata){
        plata_=plata;
    }

    bool suficiente_plata(Bus b){
        if(plata_ >= b.getprecio_()){
            return true;
        }
        else{
            return false;
        }
    }
    void cambiar_cant_plata(Bus b){
        setplata_((plata_ - b.getprecio_()));
    }
};


class Sistema {
protected:
    std::vector<Bus> buses_;
    //vectores que separan los buses segun sus tipos
    std::vector <Bus> semi_cama; 
    std::vector <Bus> salon_cama;
    std::vector <Bus> premium;
    //vectores que contienen los punteros de los buses separados por tipos  
    std::vector <Bus*> p1; 
    std::vector <Bus*> p2;
    std::vector <Bus*> p3;

    std::vector<int> indices;

    int semi;
    int salon;
    int prem;

public:
    Sistema(int buses) {
        buses_.reserve(buses);

        semi_cama.reserve(buses);
        salon_cama.reserve(buses);
        premium.reserve(buses);

        p1.reserve(buses);
        p2.reserve(buses);
        p3.reserve(buses);

        semi=0;
        salon=0;
        prem=0;
    }
    
    void agendarBus(Bus &bus) {
        buses_.push_back(bus);

        if (bus.gettipo_()=="Semi-Cama"){
                semi_cama.push_back(bus);
                p1.push_back(&bus);
            }
        else if(bus.gettipo_() =="Salon-Cama"){
                salon_cama.push_back(bus);
                p2.push_back(&bus);
            }
        else {
                premium.push_back(bus);
                p3.push_back(&bus);
            }     
    }
    
    void listarAgenda() {
        std::cout << "Selector\tOrigen\t\tDestino\t\tTipo\t\tHora" << std::endl;
        for (size_t i = 0; i<buses_.size(); i++)
        {
            std::cout << i+1 << "\t\t";
            buses_[i].info();
            std::cout << std::endl;
        }
        std::cout<<std::endl;
    }
    
    void listarBus(int bus) {
        buses_[bus-1].listarAsientos();
    } 

    

    bool venderPasaje(int bus, int asiento, Persona &a) {

        if( a.suficiente_plata(buses_[bus-1]) == false){
            std::cerr<<"La persona no tiene suficiente dinero para poder comprar el pasaje\n";
            return false;
        }

        indices.resize(buses_.size());

        for(size_t i = 0; i<buses_.size();i++){
            if (buses_[i].gettipo_()=="Semi-Cama"){;
                indices[i]=semi;
                semi++;
            }
        else if(buses_[i].gettipo_() =="Salon-Cama"){
                indices[i]=salon;
                salon++;                
            }
        else {
                indices[i]=prem;
                prem++;                
            }     
        }

        if (buses_[bus-1].gettipo_()=="Semi-Cama"){
                semi_cama[indices[bus-1]].venderAsiento(asiento, a.getrut_());
                p1[indices[bus-1]]->venderAsiento(asiento, a.getrut_());
            }
        else if(buses_[bus-1].gettipo_() =="Salon-Cama"){
                salon_cama[indices[bus-1]].venderAsiento(asiento, a.getrut_());
                p2[indices[bus-1]]->venderAsiento(asiento, a.getrut_());
            }
        else {
                premium[indices[bus-1]].venderAsiento(asiento, a.getrut_());
                p3[indices[bus-1]]->venderAsiento(asiento, a.getrut_());
            }  

            salon = prem = semi = 0;

        if (buses_[bus-1].venderAsiento(asiento, a.getrut_()) == false ) {
            std::cerr << "El asiento ya esta vendido.\n";
            return false;
        }
         a.cambiar_cant_plata(buses_[bus-1]);
    
        return true;

    }

   void estadisticas(){

        //contadores de los vectores de tipos de buses para la recopilacion de datos
        std::vector <int> semi_cama_;
        std::vector <int> salon_cama_;
        std::vector <int> premium_;

        int indice[3];

        int max1=0,max2=0,max3=0;

        indice[0]=indice[1]=indice[2]=0;

        for(int i=0;i<24;i++){
            semi_cama_.push_back(0);
        }

        salon_cama_ = semi_cama_;
        premium_=semi_cama_;

        


        for(size_t i=0;i<semi_cama.size();i++){
            for(int hora=0;hora<24;hora++){
                if(hora==semi_cama[i].gethora_()){
                    semi_cama_[hora]++;
                }        
            }
        }

        for(size_t i=0;i<salon_cama.size();i++){
            for(int hora=0;hora<24;hora++){
                if(hora==salon_cama[i].gethora_()){
                    salon_cama_[hora]++;
                }        
            }
        }

        for(size_t i=0;i<premium.size();i++){
            for(int hora=0;hora<24;hora++){
                if(hora==premium[i].gethora_()){
                    premium_[hora]++;
                }        
            }
        }        

        for(int i=0;i<24;i++){
            if(max1<semi_cama_[i]){
                max1=semi_cama_[i];
                indice[0]=i;
            }
            if(max2<salon_cama_[i]){
                max2=salon_cama_[i];
                indice[1]=i;
            }
            if(max3<premium_[i]){
                max3=premium_[i];
                indice[2]=i;
            }
        }

        std::cout<<"La hora a la que salieron mas buses del tipo "<< p1[0]->gettipo_() << " es : " <<indice[0]<<std::endl;
        std::cout<<"La hora a la que salieron mas buses del tipo "<< p2[0]->gettipo_() << " es : " <<indice[1]<<std::endl;
        std::cout<<"La hora a la que salieron mas buses del tipo "<< p3[0]->gettipo_() << " es : " <<indice[2]<<std::endl<<std::endl;

        semi_cama_.resize(12);
        salon_cama_.resize(12);
        premium_.resize(12);

        for(int i =0;i<12;i++){
            semi_cama_[i]=0;
        }

        salon_cama_=semi_cama_;
        premium_=semi_cama_;

        recorridos( semi_cama, semi_cama_);
        recorridos(salon_cama,salon_cama_);
        recorridos(premium,premium_);

        indice[0]=indice[1]=indice[2]=0;
        max1=0,max2=0,max3=0;

        for(int i = 0; i < 12 ; i++){
            if(max1<semi_cama_[i]){
                max1=semi_cama_[i];
                indice[0]=i;
            }
            if(max2<salon_cama_[i]){
                max2=salon_cama_[i];
                indice[1]=i;
            }
            if(max3<premium_[i]){
                max3=premium_[i];
                indice[2]=i;
            }
        }

        std::cout<<"El viaje mas recorrido para el bus " <<p1[0]->gettipo_() << " es "<< viajes(indice[0]) <<" que ocurrio "<< max1<<std::endl;
        std::cout<<"El viaje mas recorrido para el bus " <<p2[0]->gettipo_() <<" es "<< viajes(indice[1]) <<" que ocurrio "<< max2<<std::endl;
        std::cout<<"El viaje mas recorrido para el bus " << p3[0]->gettipo_() <<" es "<< viajes(indice[2]) <<" que ocurrio "<< max3<<std::endl<<std::endl;

        semi_cama_.resize(4);
        salon_cama_.resize(4);
        premium_.resize(4);

        for(int i=0;i<4;i++){
            semi_cama_[i]=0;
        }

        salon_cama_=semi_cama_;
        premium_=semi_cama_;

        origen_del_recorrido(semi_cama,semi_cama_);
        origen_del_recorrido(salon_cama,salon_cama_);
        origen_del_recorrido(premium,premium_);

        indice[0]=indice[1]=indice[2]=0;
        max1=0,max2=0,max3=0;

        for(int i = 0; i < 4; i++){
            if(max1<semi_cama_[i]){
                max1=semi_cama_[i];
                indice[0]=i;
            }
            if(max2<salon_cama_[i]){
                max2=salon_cama_[i];
                indice[1]=i;
            }
            if(max3<premium_[i]){
                max3=premium_[i];
                indice[2]=i;
            }
        }

        std::cout<<"El punto de origen mas repetido de el bus "<< p1[0]->gettipo_() << " es " << origen_destino(indice[0]) << " y se repite " << max1 << " veces" <<std::endl;
        std::cout<<"El punto de origen mas repetido de el bus " <<p2[0]->gettipo_() <<" es "<< origen_destino(indice[1]) << " y se repite " << max2 << " veces" <<std::endl;
        std::cout<<"El punto de origen mas repetido de el bus " <<p3[0]->gettipo_() <<" es "<< origen_destino(indice[2]) << " y se repite " << max3 << " veces" <<std::endl<<std::endl;
    
        for(int i = 0 ; i < 4 ; i++){
            semi_cama_[i]=0;
        }
        salon_cama_ = semi_cama_;
        premium_ = semi_cama_;

        final_del_recorrido(semi_cama,semi_cama_);
        final_del_recorrido(salon_cama,salon_cama_);
        final_del_recorrido(premium,premium_);

        indice[0]=indice[1]=indice[2]=0;
        max1=0,max2=0,max3=0;

        for(int i=0;i<4;i++){
            if(max1<semi_cama_[i]){
                max1=semi_cama_[i];
                indice[0]=i;
            }
            if(max2<salon_cama_[i]){
                max2=salon_cama_[i];
                indice[1]=i;
            }
            if(max3<premium_[i]){
                max3=premium_[i];
                indice[2]=i;
            }
        }

        std::cout<<"El punto de destino mas repetido de el bus "<< p1[0]->gettipo_() << " es " << origen_destino(indice[0]) << " y se repite " << max1 << " veces" <<std::endl;
        std::cout<<"El punto de destino mas repetido de el bus " <<p2[0]->gettipo_() <<" es "<< origen_destino(indice[1]) << " y se repite " << max2 << " veces" <<std::endl;
        std::cout<<"El punto de destino mas repetido de el bus " <<p3[0]->gettipo_() <<" es "<< origen_destino(indice[2]) << " y se repite " << max3 << " veces" <<std::endl;

        max1=0,max2=0,max3=0;

        for (size_t i =0;i<semi_cama.size();i++){
            max1++;
        }
       for (size_t i =0;i<salon_cama.size();i++){
            max2++;
        }

        for (size_t i =0;i<premium.size();i++){
            max3++;
        }

        imprimir_bus_mas(max1,max2,max3);   
        std::cout<<std::endl;
    }

    void imprimir_info(){

       for (size_t i = 0; i < p1.size();i++){
            p1[i]->info();
            mostrarBus(i, p1);
            std::cout<<std::endl;            
        }

        for (size_t i=0; i< p2.size();i++){
            p2[i]->info();
            mostrarBus(i, p2);
            std::cout<<std::endl;  
        }

        for (size_t i=0; i< p3.size();i++){
            p3[i]->info();
            mostrarBus(i, p3);
            std::cout<<std::endl;
        }

        estadisticas();


    }
};

#endif
