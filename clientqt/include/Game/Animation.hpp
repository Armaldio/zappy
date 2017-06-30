//
//-----------------------------------------------------------------------------
//Filename:    Animation.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/27/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_ANIMATION_HPP
#define CLIENTQT_ANIMATION_HPP

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

namespace zappy {
    class Animation {
    public:
        Animation();

        void addFrame(sf::IntRect rect);

        void setSpriteSheet(const sf::Texture &texture);

        const sf::Texture *getSpriteSheet() const;

        std::size_t getSize() const;

        const sf::IntRect &getFrame(std::size_t n) const;

    private:
        std::vector<sf::IntRect> m_frames;
        const sf::Texture *m_texture;
    };

    class AnimatedSprite : public sf::Drawable, public sf::Transformable {
    public:
        explicit AnimatedSprite(sf::Time frameTime = sf::seconds(0.2f), bool paused = false, bool looped = true);

        void update(sf::Time deltaTime);

        void setAnimation(const Animation &animation);

        void setFrameTime(sf::Time time);

        void play();

        void play(const Animation &animation);

        void pause();

        void stop();

        void setLooped(bool looped);

        void setColor(const sf::Color &color);

        const Animation *getAnimation() const;

        sf::FloatRect getLocalBounds() const;

        sf::FloatRect getGlobalBounds() const;

        bool isLooped() const;

        bool isPlaying() const;

        sf::Time getFrameTime() const;

        void setFrame(std::size_t newFrame, bool resetTime = true);

        void setSize(const sf::Vector2f & size);

    private:
        const Animation *m_animation;
        sf::Time m_frameTime;
        sf::Time m_currentTime;
        std::size_t m_currentFrame;
        sf::Vector2f m_size;
        bool m_isPaused;
        bool m_isLooped;
        const sf::Texture *m_texture;
        sf::Vertex m_vertices[4];

        virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    };

    class AnimatedText : public sf::Drawable {
    public:
        AnimatedText(const sf::String & string, const sf::Font &font, const sf::Time & time = sf::seconds(2.f));

        virtual ~AnimatedText();

        void setFont(const sf::Font &font);

        void setPosition(const sf::Vector2f &vector2);

    public:

        void update(const sf::Time &elapsedTime);

        bool isDead() const;

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        sf::Text m_text;
        sf::RectangleShape m_back;
        sf::Time m_maxTime;
        sf::Time m_currentTime;
        bool _isDead;
    };
};



#endif //CLIENTQT_ANIMATION_HPP
