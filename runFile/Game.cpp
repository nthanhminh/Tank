#include "Game.h"

    Game::Game()
    {
        menu[0].setBgPath("img/grass.png");
        menu[0].setMapPath("data/data.txt");
        menu[1].setBgPath("img/background_1.png");
        menu[1].setMapPath("data/data_1.txt");
        menu[2].setBgPath("img/background_2.png");
        menu[2].setMapPath("data/data_2.txt");
        menu[3].setBgPath("img/background_3.png");
        menu[3].setMapPath("data/data_3.txt");
        menu[4].setBgPath("img/background_4.png");
        menu[4].setMapPath("data/data_4.txt");
        menu[5].setBgPath("img/background_5.png");
        menu[5].setMapPath("data/data_5.txt");
        for (int i=0;i<5;i++)
        {
            check[i]=false;
        }
        
    }
    bool Game::loadGameChoseTank(SDL_Renderer *g_screen)
    {
        bool ret=gameChoseTank.loadImg("img/chooseMyTank.png",g_screen);
        if(ret)
        {
            return true;
        }
        return false;
    }
    bool Game::loadSoundGun()
    {
        bool ret=sound_gun.loadSound("sound/gun10.wav");
        if(ret)
            return true;
        return false;
    }
    bool Game::loadSoundCollision()
    {
        bool ret=sound_collision.loadSound("sound/gun9.wav");
        if(ret)
            return true;
        return false;
    }
    bool Game::loadSoundTank()
    {
        bool ret=sound_tank.loadSound("sound/exp.wav");
        if(ret)
            return true;
        return false;
    }
    bool Game::loadBlock(SDL_Renderer *g_screen)
    {
        for (int i=0;i<5;i++)
        {
            bool ret=block[i].loadImg("img/block.png",g_screen);
            if(!ret)
            {
                return false;
            }
        }
        return true;
    }
    bool Game::loadPauseButton(SDL_Renderer *g_screen)
    {
        bool ret=pauseButton.loadImg("img/pause.png",g_screen);
        pauseButton.setXYpos(0,0);
        if (ret==false)
        {
            return false;
        }
        else{
            return true;
        }
    }
    bool Game::loadGameRestart(SDL_Renderer *g_screen)
    {
        bool ret=gameRestart.loadImg("img/restart.png",g_screen);
        if (ret)
        {
            return true;
        }
        else return false;
    }
    bool Game::loadPHelpButton(SDL_Renderer *g_screen)
    {
        bool ret=helpBtn.loadImg("img/help_button.png",g_screen);
        if (ret==false)
        {
            return false;
        }
        else{
            return true;
        }
    }
    bool Game::loadHelpBg(SDL_Renderer *g_screen)
    {
        bool ret=gameHelp.loadImg("img/help.png",g_screen);
        if (ret==false)
        {
            return false;
        }
        else{
            return true;
        }
    }
    bool Game::loadPlayButton(SDL_Renderer *g_screen)
    {
        bool ret=playBtn.loadImg("img/playBtn.png",g_screen);
        playBtn.setXYpos(0,0);
        if (ret==false)
        {
            return false;
        }
        else{
            return true;
        }
    }
    bool Game::loadPauseBg(SDL_Renderer *g_screen)
    {
        bool ret=gamePauseBg.loadImg("img/pause_bg.png",g_screen);
        pauseButton.setXYpos(0,0);
        if (ret==false)
        {
            return false;
        }
        else{
            return true;
        }
    }
    bool Game::loadWaitingBg(SDL_Renderer *g_screen)
    {
        bool ret = waitingBg.loadImg("img/waiting.png",g_screen);
        //bool ret = waitingBg.loadImg("img//menu.png",g_screen);
        if (ret == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool Game::loadMenuGame(SDL_Renderer *g_screen)
    {
        bool ret=gameMenu.loadImg("img/menu.png",g_screen);
        if (ret == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool Game::loadGameOverBg(SDL_Renderer *g_screen)
    {
        bool ret = gameOverBg.loadImg("img//game_over.png", g_screen);
        if (ret == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool Game::loadGameWinBg(SDL_Renderer *g_screen)
    {
        bool ret = gameWinBg.loadImg("img//win.png", g_screen);
        if (ret == false)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    bool Game::loadEndGame(SDL_Renderer *g_screen)
    {
        if(!endGame.loadImg("img/end_game.png", g_screen))
        {
            return false;
        }
        return true;
    }
    bool Game::checkListEnemyTankAlive(EnemyTank *list,int size) 
    {
        int cnt = 0;
        for (int i = 0; i < size; i++)
        {
            if (list[i].getIsTankAlive() == false)
            {
                cnt++;
            }
        }
        if (cnt == size)
        {
            // gameStart = false;
            // gameWin = true;
            // gameOver = false;
            return true;
        } 
        return false;
    }


    // load music
    bool Game::loadMusicRestart()
    {
        if (!musicRestart.loadSound("sound/restart.wav"))
        {
            return false;
        }
        return true;
    }

    bool Game::loadMusicMenu()
    {

        if (!musicMenu.loadSound("sound/menu.wav"))
        {
            return false;
        } 
        return true;
    }

    bool Game::loadMusicGameWin()
    {
        if(!musicGameWin.loadSound("sound/win.wav"))
        {   
            return false;
        }
        return true;
    }

    bool Game::loadMusicClick()
    {
        if(!musicClick.loadSound("sound/click_1.wav"))
        {
            return false;
        }
        return true;
    }

    bool Game::loadMusicGameOver()
    {
        if(!musicGameOver.loadSound("sound/gameOver.wav"))
        {
            return false;
        }
        return true;
    }

    void Game::loadData(SDL_Renderer *g_screen)
    {
        menu[0].setBgPath("img/grass.png");
        menu[0].setMapPath("data/data.txt");
        menu[0].setNumberOfEnemyTank(8);
        menu[1].setBgPath("img/background_1.png");
        menu[1].setMapPath("data/data_1.txt");
        menu[1].setNumberOfEnemyTank(8);
        menu[2].setBgPath("img/background_2.png");
        menu[2].setMapPath("data/data_2.txt");
        menu[2].setNumberOfEnemyTank(8);
        menu[3].setBgPath("img/background_3.png");
        menu[3].setMapPath("data/data_3.txt");
        menu[3].setNumberOfEnemyTank(8);
        menu[4].setBgPath("img/background_4.png");
        menu[4].setMapPath("data/data_4.txt");
        menu[4].setNumberOfEnemyTank(8);
        menu[5].setBgPath("img/background_5.png");
        menu[5].setMapPath("data/data_5.txt");
        menu[5].setNumberOfEnemyTank(8);
        for (int i=menuIsOpen;i<5;i++)
        {
            check[i]=true;
        }
        std::ifstream outputFile("data/output.txt");
        if (outputFile.is_open()) {
        // Write data to the file
        while(outputFile>>menuIsOpen) {
            std::cout << "read data" << std::endl;
        }
        // Close the file
        outputFile.close();
        } 
        else 
        {
            std::cout << "Unable to open the file." << std::endl;
        }
        std::cout << menuIsOpen << std::endl;
        for (int i=menuIsOpen;i<5;i++)
        {
            check[i]=false;
        }
        if (loadWaitingBg(g_screen) == false)
        {
            std::cout << "Can not load waitingBg" << std::endl;
        }
        if (loadGameOverBg(g_screen) == false)
        {
            std::cout << "Can not load GameOver" << std::endl;
        }
        if (loadGameWinBg(g_screen) == false)
        {
            std::cout << "can not load game win" << std::endl;
        }
        if (loadMenuGame(g_screen)==false)
        {
            std::cout << "can not load game menu" << std::endl;
        }
        if (loadPauseButton(g_screen)==false)
        {
            std::cout << "can not load pause button" << std::endl;
        }
        if (loadPauseBg(g_screen) == false)
        {
            std::cout << "can not load pause bg" << std::endl;
        }
        if (!loadPlayButton(g_screen))
        {
            std::cout << "can not load play btn" << std::endl;

        }
        else
        {
            playBtn.setXYpos(650,420);
        }
        if (!loadPHelpButton(g_screen))
        {
            std::cout << "can not load help btn" << std::endl;
        }
        else
        {
            helpBtn.setXYpos(650,500);
        }
        if (!loadHelpBg(g_screen))
        {
            std::cout << "can not load help bg" << std::endl;
        }
        if(!loadEndGame(g_screen))
        {
            std::cout << "can not load end game bg" << std::endl;
        }
        if (!loadGameRestart(g_screen))
        {
            std::cout << "can not load restart bg" << std::endl;
        }
        if(!loadGameChoseTank(g_screen))
        {
            std::cout << "can not load chose tank bg" << std::endl;
        }
        if(!loadMusicMenu())
        {
            std::cout << "can not load music menu" << std::endl;
        }
        if(!loadMusicRestart())
        {
            std::cout << "can not load restart music restart" << std::endl; 
        }
        if(!loadMusicGameWin())
        {
            std::cout << "can not load win music " << std::endl;
        }
        if(!loadMusicGameOver())
        {
            std::cout << "can not load game over" << std::endl;
        }
        if (!loadMusicClick())
        {
            std::cout << "can not load music click" << std::endl;
        }
        if(!loadBlock(g_screen))
        {
            std::cout << "can not load block png" << std::endl;
        }
        if(!loadSoundGun())
        {
            std::cout << "can not load sound gun" << std::endl;
        }
        if(!loadSoundCollision())
        {
            std::cout << "can not load sound collistion" << std:: endl;
        }
        if(!loadSoundTank())
        {
            std::cout << "can not load sound tank" << std:: endl;
        }
    }
    void Game::renderBlocks(SDL_Renderer *g_screen)
    {
        block[0].setXYpos(675,230);
        block[1].setXYpos(925,230);
        block[2].setXYpos(425,390);
        block[3].setXYpos(675,390);
        block[4].setXYpos(925,390);
        if (!check[0])
        {
            block[0].render(g_screen);
        }
        if (!check[1])
        {
            block[1].render(g_screen);
        }
        if (!check[2])
        {
            block[2].render(g_screen);
        }
        if (!check[3])
        {
            block[3].render(g_screen);
        }
        if (!check[4])
        {
            block[4].render(g_screen);
        }
    }
    void Game::run(SDL_Renderer* g_screen)
    {
        musicMenu.playSound();
        musicRestart.playSound();
        musicRestart.pauseSound();
        musicGameWin.playSound();
        musicGameWin.pauseSound();
        musicGameOver.playSound();
        musicGameOver.pauseSound();
        sound_gun.playSound();
        sound_gun.pauseSound();
        sound_collision.playSound();
        sound_collision.pauseSound();
        sound_tank.pauseSound();
        while (!isQuit) 
    {
        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                isQuit = true;
                std::ofstream outputFile("data/output.txt");
                int tmp=0;
                for (int i=0;i<5;i++)
                {
                    if (check[i]==true)
                    {
                        tmp=i;
                    }
                }
                if (outputFile.is_open())
                {
    
                    std::cout << "This is line 1" << std::endl;
                    outputFile<<(tmp+1);
                    std::cout << tmp;
                    outputFile.close();
                }
                else
                {
                    std::cout << "can not load output file" << std::endl;
                }
                exit(0);
            }
            else if (g_event.type==SDL_MOUSEBUTTONDOWN)
            {
                if (g_event.button.button == SDL_BUTTON_LEFT)
                {
                    int x = g_event.button.x;
                    int y = g_event.button.y;
                    std::cout << x << " " << y << std::endl;
                    if (waiting)
                    {
                        if (x>=665 && x<=780 && y>=420 && y<=465)
                        {
                            musicClick.playSoundNoRepeat();
                            turnMenu=true;
                            waiting=false;
                        }
                        else if (x>=665 && x<=780 && y>=500 && y<=570)
                        {
                            musicClick.playSoundNoRepeat();
                            turnHelp=true;
                            waiting=false;
                        }
                    }
                    else if (turnMenu)
                    {
                        if(x>=425 && x<=545 && y>=230 && y<=350)
                        {
                            musicClick.playSoundNoRepeat();
                            choiceOfmenu=0;
                            menu[choiceOfmenu].setTankPath(tankPathChoose);
                            menu[0].loadBg(g_screen);
                            menu[0].initTank(g_screen);
                            menu[0].InitMap(g_screen);
                            turnGameStart=false;
                            turnMenu=false;
                            gameStart=true;
                        }
                        else if (x>=675 && x<=800 && y>=230 && y<=350 && check[0])
                        {
                            musicClick.playSoundNoRepeat();
                            choiceOfmenu=1;
                            turnGameStart=false;
                            turnMenu=false;
                            gameStart=true;
                            menu[choiceOfmenu].setTankPath(tankPathChoose);
                            menu[1].loadBg(g_screen);
                            menu[1].initTank(g_screen);
                            menu[1].InitMap(g_screen);
                        }
                        else if (x>=925 && x<=1045 && y>=230 && y<=350 && check[1])
                        {
                            musicClick.playSoundNoRepeat();
                            choiceOfmenu=2;
                            turnGameStart=false;
                            turnMenu=false;
                            gameStart=true;
                            menu[choiceOfmenu].setTankPath(tankPathChoose);
                            menu[2].loadBg(g_screen);
                            menu[2].initTank(g_screen);
                            menu[2].InitMap(g_screen);
                        }
                        else if (x>=425 && x<=545 && y>=390 && y<=515 && check[2])
                        {
                            musicClick.playSoundNoRepeat();
                            choiceOfmenu=3;
                            turnGameStart=false;
                            turnMenu=false;
                            gameStart=true;
                            menu[choiceOfmenu].setTankPath(tankPathChoose);
                            menu[3].loadBg(g_screen);
                            menu[3].initTank(g_screen);
                            menu[3].InitMap(g_screen);
                        }
                        else if (x>=675 && x<=800 && y>=390 && y<=515 && check[3])
                        {
                            musicClick.playSoundNoRepeat();
                            choiceOfmenu=4;
                            turnGameStart=false;
                            turnMenu=false;
                            gameStart=true;
                            menu[choiceOfmenu].setTankPath(tankPathChoose);
                            menu[4].loadBg(g_screen);
                            menu[4].initTank(g_screen);
                            menu[4].InitMap(g_screen);
                        }
                        else if (x>=925 && x<=1045 && y>=390 && y<=515 && check[4])
                        {
                            musicClick.playSoundNoRepeat();
                            choiceOfmenu=5;
                            turnGameStart=false;
                            turnMenu=false;
                            gameStart=true;
                            menu[choiceOfmenu].setTankPath(tankPathChoose);
                            menu[5].loadBg(g_screen);
                            menu[5].initTank(g_screen);
                            menu[5].InitMap(g_screen);
                        }
                        else if (x>=35 && x<=245 && y>=25 && y<=80)
                        {
                            musicClick.playSoundNoRepeat();
                            waiting=true;
                            turnMenu=false;
                        }
                        else if (x>=685 && x<=1435 && y>=30 && y<=90)
                        {
                            musicClick.playSoundNoRepeat();
                            turnChoseTank=true;
                            turnMenu=false;
                        }
                    }
                    else if (turnChoseTank)
                    {
                        if (x>=210 && x<=535 && y>=485 && y<=545)
                        {
                            musicClick.playSoundNoRepeat();
                            tankPathChoose="img/tank_1.png";
                            turnChoseTank=false;
                            turnMenu=true;
                        }
                        else if (x>=620 && x<=945 && y>=485 && y<=545)
                        {
                            musicClick.playSoundNoRepeat();
                            tankPathChoose="img/tank_2.png";
                            turnChoseTank=false;
                            turnMenu=true;
                        }
                        else if (x>=1030 && x<=1355 && y>=485 && y<=545)
                        {
                            musicClick.playSoundNoRepeat();
                            tankPathChoose="img/tank_3.png";
                            turnChoseTank=false;
                            turnMenu=true;
                        }
                    }
                    if (gameStart==true)
                    {
                        if ((x>=0 && x<=60) && (y>=0 && y<=60))
                        {
                            musicClick.playSoundNoRepeat();
                            gameStart=false;
                            gamePause=true;
                            waiting=false;
                        }
                    }
                    else  if (turnHelp)
                    {
                        if (x>=35 && x<=250 && y>=25 && y<=80)
                        {
                            musicClick.playSoundNoRepeat();
                            turnHelp=false;
                            waiting=true;
                        }
                    }
                    else if (gamePause==true)
                    {
                        if ((x>=340 && x<=1160) && (y>=380 && y<=615))
                        {
                            musicClick.playSoundNoRepeat();
                            gameStart=true;
                            gamePause=false;
                        }
                        else if (x>=185 && x<=595 && y>=120 && y<=260)
                        {
                            musicClick.playSoundNoRepeat();
                            turnMenu=true;
                            gamePause=false;
                        }
                        else if (x>+915 && x<=1322 && y>=120 && y<=260)
                        {
                            //SDL_RenderClear(g_screen);
                            musicClick.playSoundNoRepeat();
                            menu[choiceOfmenu].free();
                            menu[choiceOfmenu].setTankPath(tankPathChoose);
                            menu[choiceOfmenu].loadBg(g_screen);
                            menu[choiceOfmenu].initTank(g_screen);
                            menu[choiceOfmenu].InitMap(g_screen);
                            gameStart=true;
                            gamePause=false;
                        }

                    }
                    if (turnGameStart==true)
                    {
                        if (x>=380 && x<=600 && y>=350 && y<=402)
                        {
                            musicClick.playSoundNoRepeat();
                            turnMenu=true;
                            turnGameStart=false;
                        }
                        else if (x>=790 && x<=1000 && y>=350 && y<=402 && check[choiceOfmenu] && choiceOfmenu<5)
                        {
                            musicClick.playSoundNoRepeat();
                            choiceOfmenu++;
                            menu[choiceOfmenu].setTankPath(tankPathChoose);
                            menu[choiceOfmenu].loadBg(g_screen);
                            menu[choiceOfmenu].initTank(g_screen);
                            menu[choiceOfmenu].InitMap(g_screen);
                            gameStart=true;
                            turnGameStart=false;
                        }
                        else if (x>=585 && x<=820 && y>=510 && y<=575 )
                        {
                            musicClick.playSoundNoRepeat();
                            SDL_RenderClear(g_screen);
                            menu[choiceOfmenu].free();
                            menu[choiceOfmenu].setTankPath(tankPathChoose);
                            menu[choiceOfmenu].loadBg(g_screen);
                            menu[choiceOfmenu].initTank(g_screen);
                            menu[choiceOfmenu].InitMap(g_screen);
                            gameStart=true;
                            turnGameStart=false;
                        }
                    }

                }
            }
            else if (g_event.type==SDL_MOUSEMOTION)
            {
                if (waiting)
                {
                    int x = g_event.motion.x;
                    int y = g_event.motion.y;
                    //std::cout<< x << " " << y << std::endl;
                    if (x>=665 && x<=780 && y>=420 && y<=465)
                    {
                        if (changePlayBtn==true)
                        {
                            playBtn.setXYpos(playBtn.getXpos(),playBtn.getYpos()-changeYposHoverBtn);
                            changePlayBtn=false;
                        }
                    }
                    else
                    {
                        if(changePlayBtn==false)
                        {
                            playBtn.setXYpos(playBtn.getXpos(),playBtn.getYpos()+changeYposHoverBtn);
                            changePlayBtn=true;
                        }
                    }
                    if ((x>=665 && x<=780) && y>=500 && y<=570)
                    {
                        if (changeHelpBtn==true)
                        {
                            helpBtn.setXYpos(helpBtn.getXpos(),helpBtn.getYpos()-changeYposHoverBtn);
                            changeHelpBtn=false;
                        }
                    }
                    else{
                        if (changeHelpBtn==false)
                        {
                            helpBtn.setXYpos(helpBtn.getXpos(),helpBtn.getYpos()+changeYposHoverBtn);
                            changeHelpBtn=true;
                        }
                    }
                }   
            }
            if (gameStart==true)
            {
                if (gameStart==true)
                {
                    menu[choiceOfmenu].tank.handleEvents(g_event,menu[choiceOfmenu].walls);
                    if (menu[choiceOfmenu].tank.getIsTankAlive())
                    {
                        menu[choiceOfmenu].Bullets[menu[choiceOfmenu].sizeTankBullet].handleBulletEvents(g_event, menu[choiceOfmenu].tank, menu[choiceOfmenu].walls,g_screen,sound_gun);
                        menu[choiceOfmenu].sizeTankBullet+= 1;
                    }
                }
            }
        }
        //render background
        if (gameStart == false)
        {
            if(!Mix_Paused(musicGameWin.getChannel()))
            {
                musicGameWin.pauseSound();
            }
            if(!Mix_Paused(musicGameOver.getChannel()))
            {
                musicGameOver.pauseSound();
            }
            if (waiting)
            {
                SDL_RenderClear(g_screen);
                waitingBg.render(g_screen, NULL);   
                playBtn.render(g_screen,NULL);
                helpBtn.render(g_screen,NULL);
            }
            else if (turnHelp)
            {
                SDL_RenderClear(g_screen);
                gameHelp.render(g_screen,NULL);
            }
            else if (turnMenu==true)
            {
                SDL_RenderClear(g_screen);
                gameMenu.render(g_screen, NULL);
                renderBlocks(g_screen);
                if (Mix_Paused(musicMenu.getChannel())==1)
                {
                    musicMenu.restartSound();
                }   
                if (!Mix_Paused(musicRestart.getChannel()))
                {
                    musicRestart.pauseSound();
                }   
            }
            else if (gamePause)
            {
                SDL_RenderClear(g_screen);
                gamePauseBg.render(g_screen,NULL);
            }
            else if (turnGameStart)
            {
                SDL_RenderClear(g_screen);
                gameRestart.render(g_screen,NULL);
                if(Mix_Paused(musicRestart.getChannel())==1)
                {
                    musicRestart.restartSound();
                }
            }
            else if (turnChoseTank)
            {
                SDL_RenderClear(g_screen);
                gameChoseTank.render(g_screen,NULL);
            }
        }
        else if (gameStart == true)
        {
            if (!Mix_Paused(musicMenu.getChannel()))
            {
                musicMenu.pauseSound();
            }   
            if (!Mix_Paused(musicRestart.getChannel()))
            {
                musicRestart.pauseSound();
            }   
            if (gameOver == true)
            {
                if(Mix_Paused(musicGameOver.getChannel()))
                {
                    musicGameOver.restartSound();
                }
                SDL_RenderClear(g_screen);
                gameOverBg.render(g_screen,NULL);
                menu[choiceOfmenu].free();
                if (time_turn_restart==0)
                { 
                    turnGameStart=true;
                    gameOver=false;
                    gameStart = false;
                    time_turn_restart=6000;
                }
                else
                {
                    time_turn_restart--;
                }
            }
            else if (gameWin == true)
            {
                if(choiceOfmenu<5)
                    check[choiceOfmenu]=true;
                if(Mix_Paused(musicGameWin.getChannel()))
                {
                    musicGameWin.restartSound();
                }
                SDL_RenderClear(g_screen);
                menu[choiceOfmenu].free();
                if(choiceOfmenu!=5)
                {
                    gameWinBg.render(g_screen, NULL);
                }
                else
                {
                    endGame.render(g_screen, NULL);
                }
                if (time_turn_restart==0)
                { 
                    if(choiceOfmenu!=5)
                    {
                        turnGameStart=true;
                    }
                    else
                    {
                        turnMenu=true;
                    }
                    gameWin=false;
                    gameStart = false;
                    time_turn_restart=6000;
                }
                else
                {
                    time_turn_restart--;
                }
            }
            else
            {
            SDL_RenderClear(g_screen);
            //start
            //test
            menu[choiceOfmenu].background.render(g_screen, NULL);
            if (menu[choiceOfmenu].tank.getIsTankAlive())
            {
                menu[choiceOfmenu].tank.updateHealBar();
                SDL_Rect tmp=menu[choiceOfmenu].tank.getHealBar();
                if (menu[choiceOfmenu].tank.getTankIsProtected())
                {
                    SDL_SetRenderDrawColor(g_screen, 255, 255, 0, 255);
                    SDL_RenderFillRect(g_screen, &tmp);
                }
                else
                {
                    SDL_SetRenderDrawColor(g_screen, 255, 165, 0, 255);
                    SDL_RenderFillRect(g_screen, &tmp);
                }
                menu[choiceOfmenu].tank.renderRouteThink(g_screen, menu[choiceOfmenu].tank.getAngle(), NULL);
                if (menu[choiceOfmenu].tank.getTankIsProtected())
                {
                    if (menu[choiceOfmenu].tank.getTimeDefender()==0)
                    {
                        menu[choiceOfmenu].tank.setTankIsProtected(false);
                    }
                    else
                    {
                        menu[choiceOfmenu].tank.setTimeDefender(menu[choiceOfmenu].tank.getTimeDefender()-1);
                    }
                }
            }

            //
            for (int i = 0; i < menu[choiceOfmenu].numberOfEnemyTank; i++)
            {
               if (menu[choiceOfmenu].listEnemyTank[i].getIsTankAlive())
               {
                     if (i==0)
                        menu[choiceOfmenu].listEnemyTank[i].handleTankAI_4(menu[choiceOfmenu].walls,menu[choiceOfmenu].tank);
                    else if (i==1)
                        menu[choiceOfmenu].listEnemyTank[i].handleTankAI_6(menu[choiceOfmenu].walls,menu[choiceOfmenu].tank);
                    else if (i==3)
                        menu[choiceOfmenu].listEnemyTank[i].handleTankAI_8(menu[choiceOfmenu].walls,menu[choiceOfmenu].tank);
                    else if (i==4 || i==5)
                        menu[choiceOfmenu].listEnemyTank[i].handleAtiveTankEnemyB(menu[choiceOfmenu].tank);
                    else 
                        menu[choiceOfmenu].listEnemyTank[i].handleTankAI_2(menu[choiceOfmenu].walls,menu[choiceOfmenu].tank);
               }
               if (menu[choiceOfmenu].listEnemyTank[i].getBulletActive() && menu[choiceOfmenu].listEnemyTank[i].getIsTankAlive() && gameOver==false)
               {
                   menu[choiceOfmenu].EnemyBullets[i][menu[choiceOfmenu].sizeEnemyTankBulluets[i]].handleAutomatic(menu[choiceOfmenu].listEnemyTank[i],g_screen,sound_gun);
                   menu[choiceOfmenu].sizeEnemyTankBulluets[i]++;
                   if (menu[choiceOfmenu].sizeEnemyTankBulluets[i]>=1000)
                   {
                        menu[choiceOfmenu].setSizeEnemyTankBullet(i);
                   }
               }
            }
            menu[choiceOfmenu].tank.myTankMoveX(menu[choiceOfmenu].walls,g_screen);
            menu[choiceOfmenu].tank.MyTankMoveY(menu[choiceOfmenu].walls,g_screen);
            for (int i = 0; i < menu[choiceOfmenu].numberOfEnemyTank; i++)
            {
                menu[choiceOfmenu].listEnemyTank[i].EnemyTankMoveX(menu[choiceOfmenu].walls,g_screen,menu[choiceOfmenu].tank,menu[choiceOfmenu].listEnemyTank,menu[choiceOfmenu].numberOfEnemyTank,i);
                menu[choiceOfmenu].listEnemyTank[i].EnemyTankMoveY(menu[choiceOfmenu].walls,g_screen,menu[choiceOfmenu].tank,menu[choiceOfmenu].listEnemyTank,menu[choiceOfmenu].numberOfEnemyTank,i);

            }
            for (int i = 0; i < menu[choiceOfmenu].numberOfEnemyTank; i++)
            {
                if (menu[choiceOfmenu].listEnemyTank[i].getIsTankAlive())
                {
                    menu[choiceOfmenu].listEnemyTank[i].updateHealBar();
                    SDL_Rect tmp=menu[choiceOfmenu].listEnemyTank[i].getHealBar();

                    if (menu[choiceOfmenu].listEnemyTank[i].getTankIsProtected())
                    {
                        SDL_SetRenderDrawColor(g_screen, 255, 255, 0, 255);
                        SDL_RenderFillRect(g_screen,&tmp);
                        if (menu[choiceOfmenu].listEnemyTank[i].getTimeDefender()==0)
                        {
                            menu[choiceOfmenu].listEnemyTank[i].setTankIsProtected(false);
                        }   
                        else
                        {
                            menu[choiceOfmenu].listEnemyTank[i].setTimeDefender(menu[choiceOfmenu].listEnemyTank[i].getTimeDefender()-1);
                        }
                    }
                    else
                    {
                        SDL_SetRenderDrawColor(g_screen, 255, 0, 0, 255);
                        SDL_RenderFillRect(g_screen,&tmp);
                    }
                    menu[choiceOfmenu].listEnemyTank[i].renderRouteThink(g_screen, menu[choiceOfmenu].listEnemyTank[i].getAngle(), NULL);
                }
            }
            if (menu[choiceOfmenu].tank.getIsTankAlive())
            {
                for (int i = 0; i < menu[choiceOfmenu].sizeTankBullet; i++)
                {
                    menu[choiceOfmenu].Bullets[i].move(menu[choiceOfmenu].walls, menu[choiceOfmenu].listEnemyTank,menu[choiceOfmenu].numberOfEnemyTank,menu[choiceOfmenu].tank,g_screen,gameOver,sound_collision,sound_tank);
                    menu[choiceOfmenu].Bullets[i].renderRouteThink(g_screen, menu[choiceOfmenu].Bullets[i].getBulletAngle(), NULL);
                }
            }
            else
            {
                gameOver = true;
                time_turn_restart=5000;
            }
            // bullet enemy render
            for (int i = 0; i < menu[choiceOfmenu].numberOfEnemyTank; i++)
            {
                if (menu[choiceOfmenu].listEnemyTank[i].getIsTankAlive())
                {
                    for (int j = 0; j < menu[choiceOfmenu].sizeEnemyTankBulluets[i]; j++)
                    {
                        menu[choiceOfmenu].EnemyBullets[i][j].moveAuto(menu[choiceOfmenu].tank, menu[choiceOfmenu].walls,menu[choiceOfmenu].listEnemyTank[i],g_screen,gameOver,sound_collision,sound_tank);
                        menu[choiceOfmenu].EnemyBullets[i][j].renderRouteThink(g_screen, menu[choiceOfmenu].EnemyBullets[i][j].getBulletAngle(), NULL);
                    }
                }
            }
            for (int i = 0; i < mapRows; i++)
            {
                for (int j = 0; j < mapCols; j++)
                {
                    menu[choiceOfmenu].walls[i][j].render(g_screen, NULL);
                }
            }
            if(checkListEnemyTankAlive(menu[choiceOfmenu].listEnemyTank, menu[choiceOfmenu].numberOfEnemyTank))
            {
                gameWin = true;
                time_turn_restart=5000;
            }
            pauseButton.render(g_screen,NULL);
            SDL_Delay(15);
            }
        }
        // uapdate screen 
        SDL_RenderPresent(g_screen);
    }
        for (int i = 0; i < 6; i++)
        {
            menu[i].close();
        }
        //loadMusic();
    }