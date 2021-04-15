#include "ui/ui.h"

static GtkWidget *window;
static GtkWidget *invest_window;
static GtkWidget *recover_window;
static GtkWidget *add_contact_window;
static GtkWidget *connection_window;
static GtkWidget *create_key_window;

static GtkButton *transa_but;
static GtkButton *pkey_but;
static GtkButton *invest_but1;
static GtkButton *invest_but2;
static GtkButton *recover_but1;
static GtkButton *recover_but2;
static GtkButton *add_contact_but1;
static GtkButton *add_contact_but2;
static GtkButton *create_key_but1;
static GtkButton *create_key_but2;
static GtkButton *connect_but;
static GtkCheckButton *password_rem_but;

GtkLabel *balance_1;
GtkLabel *balance_2;
GtkLabel *private_key_label;
GtkLabel *stake_label1;
GtkLabel *stake_label2;
GtkLabel *stake_label3;
GtkEntry *transa_amount;
GtkEntry *recipient_key;
GtkEntry *invest_entry;
GtkEntry *recover_entry;
GtkEntry *name_entry_con;
GtkEntry *public_key_entry_con;
GtkEntry *password_entry1;
GtkEntry *password_entry2;
GtkTreeView *tv_con;
GtkTreeStore *ts_con;
GtkTreeViewColumn *cx1_con;
GtkTreeViewColumn *cx2_con;
GtkCellRenderer *cr1_con;
GtkCellRenderer *cr2_con;
GtkTreeView *tv_th;
GtkTreeStore *ts_th;
GtkTreeViewColumn *cx1_th;
GtkTreeViewColumn *cx2_th;
GtkTreeViewColumn *cx3_th;
GtkTreeViewColumn *cx4_th;
GtkCellRenderer *cr1_th;
GtkCellRenderer *cr2_th;
GtkCellRenderer *cr3_th;
GtkCellRenderer *cr4_th;


int setup()
{
    GtkBuilder *builder;
    GError *err = NULL;

    builder = gtk_builder_new();
    if(gtk_builder_add_from_file(builder, "pepitas.glade", &err) == 0)
    {
        fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
        return 1;
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "Pepitas"));
    invest_window = GTK_WIDGET(gtk_builder_get_object(builder, "invest_window"));
    recover_window = GTK_WIDGET(gtk_builder_get_object(builder, "recover_window"));
    add_contact_window = GTK_WIDGET(gtk_builder_get_object(builder, "add_contact_window"));
    connection_window = GTK_WIDGET(gtk_builder_get_object(builder, "connection_window"));
    create_key_window = GTK_WIDGET(gtk_builder_get_object(builder, "create_key_window"));

    transa_but = GTK_BUTTON(gtk_builder_get_object(builder, "transa_but"));

    pkey_but = GTK_BUTTON(gtk_builder_get_object(builder, "show_pkey_but"));

    invest_but1 = GTK_BUTTON(gtk_builder_get_object(builder, "invest_but1"));
    invest_but2 = GTK_BUTTON(gtk_builder_get_object(builder, "invest_but2"));

    recover_but1 = GTK_BUTTON(gtk_builder_get_object(builder, "recover_but1"));
    recover_but2 = GTK_BUTTON(gtk_builder_get_object(builder, "recover_but2"));

    invest_entry = GTK_ENTRY(gtk_builder_get_object(builder, "invest_entry"));
    recover_entry = GTK_ENTRY(gtk_builder_get_object(builder, "recover_entry"));

    transa_amount = GTK_ENTRY(gtk_builder_get_object(builder, "transa_amount"));

    recipient_key = GTK_ENTRY(gtk_builder_get_object(builder, "recipient_key"));

    tv_con = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeviewCON"));
    ts_con = GTK_TREE_STORE(gtk_builder_get_object(builder, "treestoreCON"));
    cx1_con = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "Name"));
    cx2_con = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "Public key"));
    cr1_con = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cellrenderertext1"));
    cr2_con = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cellrenderertext2"));
    add_contact_but1 = GTK_BUTTON(gtk_builder_get_object(builder, "add_contact_but1"));
    add_contact_but2 = GTK_BUTTON(gtk_builder_get_object(builder, "add_contact_but2"));
    name_entry_con = GTK_ENTRY(gtk_builder_get_object(builder, "name_entry_con"));
    public_key_entry_con = GTK_ENTRY(gtk_builder_get_object(builder, "public_key_entry_con"));

    tv_th = GTK_TREE_VIEW(gtk_builder_get_object(builder, "treeviewTH"));
    ts_th = GTK_TREE_STORE(gtk_builder_get_object(builder, "treestoreTH"));
    cx1_th = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "Amount"));
    cx2_th = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "public_key_th"));
    cx3_th = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "Date"));
    cx4_th = GTK_TREE_VIEW_COLUMN(gtk_builder_get_object(builder, "Validated"));
    cr1_th = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cellrenderertext3"));
    cr2_th = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cellrenderertext4"));
    cr3_th = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cellrenderertext5"));
    cr4_th = GTK_CELL_RENDERER(gtk_builder_get_object(builder, "cellrenderertext6"));

    password_entry1 = GTK_ENTRY(gtk_builder_get_object(builder, "password_entry1"));
    password_entry2 = GTK_ENTRY(gtk_builder_get_object(builder, "password_entry2"));

    password_rem_but = GTK_CHECK_BUTTON(gtk_builder_get_object(builder, "password_rem_but"));
    create_key_but1 = GTK_BUTTON(gtk_builder_get_object(builder, "create_key_but1"));
    create_key_but2 = GTK_BUTTON(gtk_builder_get_object(builder, "create_key_but2"));
    connect_but = GTK_BUTTON(gtk_builder_get_object(builder, "connect_but"));

    private_key_label = GTK_LABEL(gtk_builder_get_object(builder, "private_key_label"));
    balance_1 = GTK_LABEL(gtk_builder_get_object(builder, "balance_1");
    balance_2 = GTK_LABEL(gtk_builder_get_object(builder, "balance_2");
    stake_label1 = GTK_LABEL(gtk_builder_get_object(builder, "stake_label1");
    stake_label2 = GTK_LABEL(gtk_builder_get_object(builder, "stake_label2");
    stake_label3 = GTK_LABEL(gtk_builder_get_object(builder, "stake_label3");

    gtk_widget_hide(GTK_WIDGET(private_key_label));
    gtk_widget_hide(invest_window);
    gtk_widget_hide(recover_window);
    gtk_widget_hide(add_contact_window);
    gtk_widget_hide(window);
    gtk_widget_hide(create_key_window);

    g_signal_connect(transa_but, "clicked", G_CALLBACK(on_transaction_button_press), NULL);
    g_signal_connect(pkey_but, "clicked", G_CALLBACK(on_pkey_button_press), NULL);
    g_signal_connect(invest_but1, "clicked", G_CALLBACK(on_invest_button1_press), NULL);
    g_signal_connect(invest_but2, "clicked", G_CALLBACK(on_invest_button2_press), NULL);
    g_signal_connect(recover_but1, "clicked", G_CALLBACK(on_recover_button1_press), NULL);
    g_signal_connect(recover_but2, "clicked", G_CALLBACK(on_recover_button2_press), NULL);
    g_signal_connect(add_contact_but1, "clicked", G_CALLBACK(on_add_contact_button1_press), NULL);
    g_signal_connect(add_contact_but2, "clicked", G_CALLBACK(add_contact), NULL);
    g_signal_connect(create_key_but1, "clicked", G_CALLBACK(on_create_key_but1_press), NULL);
    g_signal_connect(create_key_but2, "clicked", G_CALLBACK(on_create_key_but2_press), NULL);
    g_signal_connect(connect_but, "clicked", G_CALLBACK(on_connect_but_press), NULL);

    g_signal_connect(window, "destroy", G_CALLBACK(on_main_window_destroy), NULL);
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(connection_window);

    return 0;
}

gboolean on_main_window_delete(
            GtkWidget *widget, __attribute__((unused)) gpointer data)
{
    g_print("Quitting app...\n");
    gtk_widget_destroy(widget);
    return TRUE;

}

void on_main_window_destroy(__attribute__ ((unused)) GtkWidget *widget,
                            __attribute__ ((unused)) gpointer data)
{
    gtk_main_quit();
    g_print("App closed\n");
}

gboolean on_transaction_button_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused))gpointer user_data)
{
     //Call to transaction function
     return TRUE;
}

gboolean on_pkey_button_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    if(strcmp(gtk_button_get_label(pkey_but), "Show key") == 0)
    {
        gtk_button_set_label(pkey_but, "Hide key");
        gtk_widget_show(GTK_WIDGET(private_key_label));
    }
    else
    {
        gtk_button_set_label(pkey_but, "Show key");
        gtk_widget_hide(GTK_WIDGET(private_key_label));
    }

    return TRUE;
}

gboolean on_invest_button1_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    gtk_widget_show(invest_window);

    return TRUE;
}

gboolean on_invest_button2_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    //Call to the invest function
    gtk_widget_hide(invest_window);
    gtk_entry_set_text(invest_entry, "");

    return TRUE;
}
gboolean on_recover_button1_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    gtk_widget_show(recover_window);

    return TRUE;
}

gboolean on_recover_button2_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    //Call to the recover function
    gtk_widget_hide(recover_window);
    gtk_entry_set_text(recover_entry, "");

    return TRUE;
}

gboolean on_add_contact_button1_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    gtk_widget_show(add_contact_window);
    return TRUE;
}


gboolean add_contact(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    if(strcmp(gtk_entry_get_text(public_key_entry_con),"") != 0 && 
       strcmp(gtk_entry_get_text(name_entry_con),"") != 0)
    {
        GtkTreeIter iter;

        gtk_tree_store_append(ts_con, &iter, NULL);
        gtk_tree_store_set(ts_con, &iter, 0, gtk_entry_get_text(name_entry_con), -1);
        gtk_tree_store_set(ts_con, &iter, 1, gtk_entry_get_text(public_key_entry_con), -1);

        gtk_entry_set_text(name_entry_con, "");
        gtk_entry_set_text(public_key_entry_con, "");
    }

    gtk_widget_hide(add_contact_window);
    return TRUE;
}

gboolean on_create_key_but1_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    gtk_widget_show(create_key_window);
    return TRUE;

}

gboolean on_create_key_but2_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{

    //create key function
    gtk_widget_hide(create_key_window);
    return TRUE;
}

gboolean on_connect_but_press(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    //if(strcmp(gtk_entry_get_text(password_entry1), key_hash_function)
    update_labels();
    gtk_widget_hide(connection_window);
    gtk_widget_show(window);


    return TRUE;
}

gboolean update_labels(__attribute__ ((unused)) GtkWidget *widget,
                    __attribute__ ((unused)) GdkEventKey *event,
                    __attribute__ ((unused)) gpointer user_data)
{
    /*
    if(atol(gtk_label_get_text(balance_1)) != Get_Balance)
    {
        char buff1[30];
        sprintf(buff, "%lu",Get_Balance);
        gtk_label_set_text(balance_1, buff1);
        gtk_label_set_text(balance_2, buff1);
    }
    if(atol(gtk_label_get_text(stake_label1)) != Get_Stake)
    {
        char buff2[30];
        sprintf(buff, "%lu",Get_Stake);
        gtk_label_set_text(stake_label1, buff2);
        gtk_label_set_text(stake_label2, buff2);
        gtk_label_set_text(stake_label3, buff2);
    }
    */
    return TRUE;
}
