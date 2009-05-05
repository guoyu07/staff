﻿// i18n: internationalization object

i18n = 
{
  tLocales: {},
  tLocale: {},
  sLocale: '',
  
  LoadLocale: function(sNamespace, sPath, fnComplete, tOptions)
  {
    var tOpts = tOptions || {};
    if (tOpts.sLocale == null)
    {
      tOpts.sLocale = navigator.userLanguage || navigator.language;
    }
    
    function OnLoaded()
    {
      if(i18n.tLocales[tOpts.sLocale] == null)
      {
        i18n.tLocales[tOpts.sLocale] = i18n[sNamespace];
      }
      else
      {
        var tLoc = i18n.tLocales[tOpts.sLocale];
        var tNewLoc = i18n[sNamespace];
        for(var nIndex in tNewLoc)
        {
          tLoc[nIndex] = tNewLoc[nIndex];
        }
      }
      
      if (tOpts.bSwitchTo !== false)
      {
        i18n.SetLocale(tOpts.sLocale);
      }
      fnComplete && fnComplete();
    }
    
    function OnError()
    {
      alert("can't load locale: \"" + tOpts.sLocale + "\" for " + sNamespace);
    }

    Include(tOpts.sLocale, (sPath != '' ? sPath + '/' : '') + 'assets/i18n/', OnLoaded, [ 'i18n.' + sNamespace ], OnError);
  },
  
  SetLocale: function(sLocale)
  {
    this.tLocale = this.tLocales[sLocale] || {};
    this.sLocale = sLocale;
  },
  
  GetLocale: function()
  {
    return sLocale;
  },
  
  Translate: function(sText)
  {
    return (i18n.tLocale && i18n.tLocale[sText]) || sText;
  }
};

// shortcut for translation function
_ = i18n.Translate;