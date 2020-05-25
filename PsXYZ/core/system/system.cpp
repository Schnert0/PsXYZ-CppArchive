#include "system.h"

System::System(Renderer* rendererPtr){
    renderer = rendererPtr;

    gpu = new GPU;
    bus = new Bus;
    dma = new DMA;
    cpu = new CPU;

    gpu->getComponents(renderer);
    bus->getComponents(gpu, dma);
    dma->getComponents(gpu, bus);
    cpu->getComponents(bus);
}


System::~System(){
    delete cpu;
    delete dma;
    delete bus;
    delete gpu;
}

void System::reset(){
    gpu->reset();
    dma->reset();
    bus->reset();
    cpu->reset();
}


void System::loadBIOS(const char* path){
    bus->loadBIOS(path);
}


void System::run(){
    cpu->runFrame();
}