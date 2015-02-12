USE [myTestDB]
GO

/****** Object:  Table [dbo].[ShoppingListFood]    Script Date: 15.12.2014 11:43:23 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[ShoppingListFood](
	[ID] [int] NOT NULL,
	[Food] [text] NULL,
	[Quantity] [text] NULL,
	[Buy] [int] NULL,
 CONSTRAINT [PK_ShoppingListFood] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY] TEXTIMAGE_ON [PRIMARY]

GO

ALTER TABLE [dbo].[ShoppingListFood]  WITH CHECK ADD  CONSTRAINT [FK_ShoppingListFood_ShoppingList] FOREIGN KEY([ID])
REFERENCES [dbo].[ShoppingList] ([ShopListID])
GO

ALTER TABLE [dbo].[ShoppingListFood] CHECK CONSTRAINT [FK_ShoppingListFood_ShoppingList]
GO


