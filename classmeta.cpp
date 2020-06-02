#include "classmeta.h"

ClassMeta::ClassMeta(QString meta_id, QString udc, QString invent_num, QString title_of_the_book, QString discipline,
                     QString type_of_obs, QString option, QString copyright_mark, QString authors, QString publ_language, QString country,
                     QString place_of_publ, QString year_of_publ, QString view_type, QString num_of_pages,
                     QString start_of_obs, QString end_of_obs, QString obs_area, QString volume,
                     QString realease, QString series, QString part, QString access, QString prod_method,
                     QString meta_creation_date, QString oper_name, QString last_modif_date , QString directory) :
    meta_id(meta_id), udc(udc), invent_num(invent_num), title_of_the_book(title_of_the_book), discipline(discipline),
    type_of_obs(type_of_obs), option(option), copyright_mark(copyright_mark), authors(authors), publ_language(publ_language), country(country),
    place_of_publ(place_of_publ), year_of_publ(year_of_publ), view_type(view_type), num_of_pages(num_of_pages), start_of_obs(start_of_obs),
    end_of_obs(end_of_obs), obs_area(obs_area), volume(volume), realease(realease), series(series),
    part(part), access(access), prod_method(prod_method), meta_creation_date(meta_creation_date),
    oper_name(oper_name), last_modif_date(last_modif_date), directory(directory)

{

}

ClassMeta::ClassMeta (const ClassMeta& obj):
    meta_id(obj.meta_id), udc(obj.udc), invent_num(obj.invent_num), title_of_the_book(obj.title_of_the_book), discipline(obj.discipline),
    type_of_obs(obj.type_of_obs), option(obj.option), copyright_mark(obj.copyright_mark), authors(obj.authors), publ_language(obj.publ_language),
    country(obj.country), place_of_publ(obj.place_of_publ), year_of_publ(obj.year_of_publ), view_type(obj.view_type), num_of_pages(obj.num_of_pages),
    start_of_obs(obj.start_of_obs),end_of_obs(obj.end_of_obs), obs_area(obj.obs_area), volume(obj.volume),
    realease(obj.realease), series(obj.series),part(obj.part), access(obj.access), prod_method(obj.prod_method),
    meta_creation_date(obj.meta_creation_date),oper_name(obj.oper_name), last_modif_date(obj.last_modif_date), directory(obj.directory)
{

}
QString ClassMeta::get_id() const
{
    return meta_id;
}
QString ClassMeta::get_udc() const
{
    return udc;
}
QString ClassMeta::get_invent_num() const
{
    return invent_num;
}
QString ClassMeta::get_title() const
{
    return title_of_the_book;
}
QString ClassMeta::get_discipline() const
{
    return  discipline;
}
QString ClassMeta::get_type_of_obs() const
{
    return type_of_obs;
}
QString ClassMeta::get_option() const
{
    return option;
}
QString ClassMeta::get_cop_mark() const
{
    return copyright_mark;
}
QString ClassMeta::get_authors() const
{
    return  authors;
}
QString ClassMeta::get_publ_language() const
{
    return  publ_language;
}
QString ClassMeta::get_country() const
{
    return country;
}
QString ClassMeta::get_place_of_publ() const
{
    return place_of_publ;
}
QString ClassMeta::get_year_of_publ() const
{
    return year_of_publ;

}
QString ClassMeta::get_view_type() const
{
    return view_type;
}
QString ClassMeta::get_num_of_pages() const
{
    return  num_of_pages;
}
QString ClassMeta::get_start_of_obs() const
{
    return start_of_obs;
}
QString ClassMeta::get_end_of_obs() const
{
    return end_of_obs;
}
QString ClassMeta::get_obs_area() const
{
    return obs_area;
}
QString ClassMeta::get_volume() const
{
    return volume;
}
QString ClassMeta::get_realease() const
{
    return realease;
}
QString ClassMeta::get_series() const
{
    return series;
}
QString ClassMeta::get_part() const
{
    return part;
}
QString ClassMeta::get_access() const
{
    return access;
}

QString ClassMeta::get_prod_method() const
{
    return prod_method;
}
QString ClassMeta::get_meta_cr_date() const
{
    return meta_creation_date;
}
QString ClassMeta::get_oper_name() const
{
    return oper_name;
}
QString ClassMeta::get_last_modif_date() const
{
    return last_modif_date;
}
QString ClassMeta::get_directory() const
{
    return directory;
}

void ClassMeta::set_id(QString value)
{
    meta_id = value;
}

void ClassMeta::set_udc(QString value)
{
    udc = value;
}

void ClassMeta::set_invent_num(QString value)
{
    invent_num = value;
}

void ClassMeta::set_title(QString value)
{
    title_of_the_book = value;
}

void ClassMeta::set_discipline(QString value)
{
    discipline = value;
}

void ClassMeta::set_type_of_obs(QString value)
{
    type_of_obs = value;
}

void ClassMeta::set_option(QString value)
{
    option = value;
}

void ClassMeta::set_cop_mark(QString value)
{
    copyright_mark = value;
}

void ClassMeta::set_authors(QString value)
{
    authors = value;
}

void ClassMeta::set_publ_language(QString value)
{
    publ_language = value;
}

void ClassMeta::set_country(QString value)
{
    country = value;
}

void ClassMeta::set_place_of_publ(QString value)
{
    place_of_publ = value;
}

void ClassMeta::set_year_of_publ(QString value)
{
    year_of_publ = value;
}

void ClassMeta::set_view_type(QString value)
{
    view_type = value;
}

void ClassMeta::set_num_of_pages(QString value)
{
    num_of_pages = value;
}

void ClassMeta::set_start_of_obs(QString value)
{
    start_of_obs = value;
}

void ClassMeta::set_end_of_obs(QString value)
{
    end_of_obs = value;
}

void ClassMeta::set_obs_area(QString value)
{
    obs_area = value;
}

void ClassMeta::set_volume(QString value)
{
    volume = value;
}

void ClassMeta::set_realease(QString value)
{
    realease = value;
}

void ClassMeta::set_series(QString value)
{
    series = value;
}

void ClassMeta::set_part(QString value)
{
    part = value;
}

void ClassMeta::set_access(QString value)
{
    access = value;
}

void ClassMeta::set_prod_method(QString value)
{
    prod_method = value;
}

void ClassMeta::set_meta_cr_date(QString value)
{
    meta_creation_date = value;
}

void ClassMeta::set_oper_name(QString value)
{
    oper_name = value;
}

void ClassMeta::set_last_modif_date(QString value)
{
    last_modif_date = value;
}

void ClassMeta::set_directory(QString value)
{
    directory = value;
}
