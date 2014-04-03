#include <SFML/Graphics.hpp>
#include <button.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800,600,32), "Starfield Example", sf::Style::Default);

    sf::Font myfont;
    if(!myfont.loadFromFile("fonts/contb.ttf"))//http://www.dafont.com/continuum.font
    {
        std::cerr<<"Could not find contb.ttf font."<<std::endl;
    }

    gui::button yeah("Yeah!", myfont, sf::Vector2f(100.f,100.f), gui::style::save);
    gui::button nope("Nope", myfont, sf::Vector2f(100.f, 200.f), gui::style::cancel);
    gui::button nice("Nice...", myfont, sf::Vector2f(300.f, 100.f), gui::style::clean);
    gui::button custom("Sweet", myfont, sf::Vector2f(300.f, 200.f), gui::style::none);
    custom.setBorderThickness(2.f);
    custom.setBorderRadius(20.f);
    custom.setBorderColor(sf::Color(255,255,255,255));
    custom.setColorNormal(sf::Color(200,0,200,255));
    custom.setColorHover(sf::Color(255,0,255,100));
    custom.setColorClicked(sf::Color(150,0,150,255));
    custom.setColorTextNormal(sf::Color(255,255,255,255));
    custom.setColorTextHover(sf::Color(255,255,0,255));
    custom.setColorTextClicked(sf::Color(255,0,0,255));

    sf::Event e;
    bool running = true;
    while(running)
    {
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
        }
            yeah.update(e,window);
            nope.update(e,window);
            nice.update(e,window);
            custom.update(e,window);

            window.clear();
            window.draw(yeah);
            window.draw(nope);
            window.draw(nice);
            window.draw(custom);
            window.display();
    }
    return 0;
}
