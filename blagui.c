#include <SDL3/SDL.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD)) {
        return 1;
    }
    
    SDL_Window *window = SDL_CreateWindow(
        "0",
        0, 0,
        SDL_WINDOW_FULLSCREEN | SDL_WINDOW_BORDERLESS
    );
    if (!window) {
        SDL_Quit();
        return 1;
    }
    
    SDL_HideCursor();
    
    SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    
    bool running = true;
    SDL_Event e;
    while (running) {
        if (SDL_WaitEvent(&e)) {
            switch (e.type) {
                case SDL_EVENT_KEY_DOWN:            // Any keyboard key
                case SDL_EVENT_MOUSE_BUTTON_DOWN:   // Any mouse button (left, right, middle, side)
                case SDL_EVENT_MOUSE_WHEEL:         // Mouse scroll wheel
                case SDL_EVENT_FINGER_DOWN:         // Touch screen tap
                case SDL_EVENT_GAMEPAD_BUTTON_DOWN: // Gamepad / controller button
                case SDL_EVENT_QUIT:                // Window close / system signal
                    running = false;
                    break;
                default:
                    break;
            }
        }
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}