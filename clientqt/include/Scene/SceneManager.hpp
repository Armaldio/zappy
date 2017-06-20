//
//-----------------------------------------------------------------------------
//Filename:    SceneManager.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/20/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_SCENEMANAGER_HPP
#define CLIENTQT_SCENEMANAGER_HPP

#include <include/Scene/Scene.hpp>
#include <vector>
#include "Singleton.hpp"

namespace zappy {
    class SceneManager : public zappy::Singleton<SceneManager> {
    private:
        Scene   *_currentScene;
        std::vector<Scene *> _scenes;

    public:
        SceneManager();

        virtual ~SceneManager();

        void loadRessources();

        void unloadRessources();

        void loadAllRessources();

        void unloadAllRessources();

        void update();

        void draw();

        Scene *getCurrentScene();

        bool addScene(Scene *scene);

        Scene *selectScene(std::string const& name);

        bool runScene(std::string const & name);
    };
};


#endif //CLIENTQT_SCENEMANAGER_HPP
