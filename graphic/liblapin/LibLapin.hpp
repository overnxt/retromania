#ifndef			LIBLAPIN_H
# define		LIBLAPIN_H

# include		<map>
# include		<lapin.h>
# include		"AGraphic.hpp"

namespace retromania
{

t_bunny_response	mainLoop(void *);
t_bunny_response	keyResponse(t_bunny_event_state,
				    t_bunny_keysym,
				    void *);

class			LibLapin : public AGraphic
{
  using pictureTab_t	= std::map<ColorType, t_bunny_picture *>;
  using inputTab_t	= std::map<t_bunny_keysym, InputType>;
  using configTab_t	= std::map<int, t_bunny_picture *>;

  private:
    static const int		_FIRST_PRINTABLE;
    static const int		_LETTER_WIDTH;
    static const int		_LETTER_HEIGHT;
    static const int		_UNIT;
    static const int		_WIN_HEIGHT;
    static const int		_WIN_WIDTH;
    static const std::string	_NAME;

    inputTab_t		_inputTab;
    t_bunny_window	*_window;
    InputType		_input;
    pictureTab_t	_fonts;
    configTab_t		_configTab;

    void 		blitBackground() const;
    t_bunny_picture	*openPicture(const char *);
    void 		initColoredFonts();
    void 		initConfigTab();
    void 		initInputTab();

  public:
			LibLapin();
			~LibLapin();
    /*
    ** Inherited methods from IGraphic
    */
    virtual InputType	getInput() const;
    virtual void 	setConfig(const Sptr_t<conf_t> config);
    virtual const std::string&	getName() const;

    virtual void	createWindow();
    virtual void 	quitWindow();
    virtual void 	blitTile(int const, retromania::Pos &);
    virtual void	blitText(std::string const &,
				 retromania::Pos const &,
				 int const,
				 ColorType const);
    virtual void 	display(Sptr_t<Map> const map = nullptr);

    inputTab_t&		getInputTab();
    void 		setInput(InputType);
  private:

};
}
#endif			/* !LIBLAPIN_H */
