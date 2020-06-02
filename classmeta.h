#ifndef CLASSMETA_H
#define CLASSMETA_H

#include <QString>

class ClassMeta
{
private:
    QString meta_id, udc, invent_num, title_of_the_book, discipline, type_of_obs, option, copyright_mark, authors, publ_language, country,
    place_of_publ, year_of_publ, view_type, num_of_pages, start_of_obs, end_of_obs,
    obs_area, volume, realease, series, part, access, prod_method, meta_creation_date,
    oper_name, last_modif_date, directory;
public:
    ClassMeta(QString meta_id = "", QString udc = "", QString invent_num = "", QString title_of_the_book = "", QString discipline = "",
              QString type_of_obs = "", QString option = "", QString copyright_mark = "", QString authors = "", QString publ_language = "",
              QString country = "", QString place_of_publ = "", QString year_of_publ = "", QString view_type = "", QString num_of_pages = "",
              QString start_of_obs = "", QString end_of_obs = "", QString obs_area = "", QString volume = "",
              QString realease = "", QString series = "", QString part = "", QString access = "", QString prod_method = "",
              QString meta_creation_date = "", QString oper_name = "", QString last_modif_date = "", QString directory = "");

    ClassMeta (const ClassMeta& obj);

    QString get_id() const;
    QString get_udc() const;
    QString get_invent_num() const;
    QString get_title() const;
    QString get_discipline() const;
    QString get_type_of_obs() const;
    QString get_option() const;
    QString get_cop_mark() const;
    QString get_authors() const;
    QString get_publ_language() const;
    QString get_country() const;
    QString get_place_of_publ() const;
    QString get_year_of_publ() const;
    QString get_view_type() const;
    QString get_num_of_pages() const;
    QString get_start_of_obs() const;
    QString get_end_of_obs() const;
    QString get_obs_area() const;
    QString get_volume() const;
    QString get_realease() const;
    QString get_series() const;
    QString get_part() const;
    QString get_access() const;
    QString get_prod_method() const;
    QString get_meta_cr_date() const;
    QString get_oper_name() const;
    QString get_last_modif_date() const;
    QString get_directory() const;

    void set_id(QString value);
    void set_udc(QString value);
    void set_invent_num(QString value);
    void set_title(QString value);
    void set_discipline(QString value);
    void set_type_of_obs(QString value);
    void set_option(QString value);
    void set_cop_mark(QString value);
    void set_authors(QString value);
    void set_publ_language(QString value);
    void set_country(QString value);
    void set_place_of_publ(QString value);
    void set_year_of_publ(QString value);
    void set_view_type(QString value);
    void set_num_of_pages(QString value);
    void set_start_of_obs(QString value);
    void set_end_of_obs(QString value);
    void set_obs_area(QString value);
    void set_volume(QString value);
    void set_realease(QString value);
    void set_series(QString value);
    void set_part(QString value);
    void set_access(QString value);
    void set_prod_method(QString value);
    void set_meta_cr_date(QString value);
    void set_oper_name(QString value);
    void set_last_modif_date(QString value);
    void set_directory(QString value);

    //деструктор!!!!!!!


};

#endif // CLASSMETA_H
